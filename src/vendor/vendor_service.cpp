/******************************************************************************
 * Arquivo     : vendor_service.cpp
 * Autor       : Luís Moreira
 * Criado em   : 04/07/2025
 * Descrição   : Arquivo cpp responsável pela implementação da classe VendorService
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 04/07/2025: Versão inicial (Luís Moreira)
 ******************************************************************************/

#include "vendor_service.h"
#include <iostream>
#include "vendor.h"
#include "../include/json.hpp"
#include <fstream>
#include <conio.h>
#include "../shared/Console_utils.h"

using json = nlohmann::json;

void VendorService::create()
{
  std::string name, cnpj, phone_number, email, cep;
  std::cout << "Iniciando criacao de novo fornecedor..." << std::endl;
  std::cout << "Informe o nome do Fornecedor: ";
  std::cin >> name;
  std::cout << "Informe o CNPJ do Fornecedor: ";
  std::cin >> cnpj;
  std::cout << "Informe o número de telefone do Fornecedor: ";
  std::cin >> phone_number;
  std::cout << "Informe o CEP do Fornecedor: ";
  std::cin >> cep;
  std::cout << "Informe o email do Fornecedor: ";
  std::cin >> email;

  Vendor newVendor;
  const bool condition = newVendor.init(name, cnpj, phone_number, email, cep);

  if (!condition)
  {
    std::cout << "Nao foi possivel criar usuário. Erro na validação" << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json jsonObj = newVendor.toJson();

  std::ifstream inFile("../db.json");
  if (!inFile.is_open())
  {
    std::cout << "Nao foi possivel abrir o arquivo JSON." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json db;

  inFile >> db;
  inFile.close();

  db["vendor"].push_back(jsonObj);

  std::ofstream outFile("../db.json");
  outFile << db.dump(4);
  outFile.close();

  std::cout << "Fornecedor criado com sucesso!" << std::endl;

  ConsoleUtils::pause_and_clear();
}

void VendorService::getAll()
{
  std::cout << "Exibindo a lista de fornecedores..." << std::endl;
  std::ifstream inFile("../db.json");
  if (!inFile.is_open())
  {
    std::cout << "Nao foi possivel abrir o arquivo JSON." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json db;
  inFile >> db;
  inFile.close();

  if (!db.contains("vendor") || db["vendor"].empty())
  {
    std::cout << "Nenhum Fornecedor criado." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }
  for (const auto &item : db["vendor"])
  {
    std::cout
        << "================================="
        << std::endl
        << "   Nome: " << item.value("name", "")
        << std::endl
        << "   CNPJ: " << item.value("cnpj", "")
        << std::endl
        << "   Telefone: " << item.value("phone_number", "")
        << std::endl
        << "   Email " << item.value("email", "") << std::endl
        << "   CEP: " << item.value("cep", "") << std::endl
        << "================================="
        << std::endl;
    std::cout << "Aperte ENTER para o proximo Fornecedor" << std::endl;
    ConsoleUtils::wait_for_enter();
  }
  std::cout << "Todos os Fornecedores foram listados" << std::endl;
  ConsoleUtils::pause_and_clear();
}

void VendorService::getOne()
{
  std::string vendor_cnpj;
  std::cout << "Informe o CNPJ do Fornecedor que deseja visualizar:";
  std::cin >> vendor_cnpj;

  std::ifstream inFile("../db.json");
  if (!inFile.is_open())
  {
    std::cout << "Nao foi possivel abrir o arquivo JSON." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json db;
  inFile >> db;
  inFile.close();

  bool found = false;
  if (db.contains("vendor"))
  {
    for (const auto &item : db["vendor"])
    {
      if (item.value("cnpj", "") == vendor_cnpj)
      {
        std::cout << "Detalhes do Fornecedor:"
                  << std::endl
                  << "   Nome: " << item.value("name", "")
                  << std::endl
                  << "   CNPJ: " << item.value("cnpj", "")
                  << std::endl
                  << "   Telefone: " << item.value("phone_number", "")
                  << std::endl
                  << "   Email " << item.value("email", "") << std::endl
                  << "   CEP: " << item.value("cep", "") << std::endl;
        found = true;
        break;
      }
    }
  }
  if (!found)
  {
    std::cout << "Fornecedor nao encontrado." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }
  ConsoleUtils::pause_and_clear();
}

// void VendorService::deleteItem() {}
// void VendorService::update() {}

void VendorService::updatePhoneNumberVendor()
{
  std::string cnpj_vendor, phone_number;
  std::cout << "Informe o CNPJ do Fornecedor que deseja atualizar o número de telefone:";
  std::cin >> cnpj_vendor;

  std::ifstream inFile("../db.json");
  if (!inFile.is_open())
  {
    std::cout << "Nao foi possivel abrir o arquivo JSON." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json db;
  inFile >> db;
  inFile.close();

  bool found = false;
  if (db.contains("vendor"))
  {
    for (auto &item : db["vendor"])
    {
      if (item.value("cnpj", "") == cnpj_vendor)
      {
        std::cout << "Informe o novo número: ";
        std::cin >> phone_number;
        item["phone_number"] = phone_number;
        found = true;
        break;
      }
    }
  }

  if (!found)
  {

    std::cout << "Fornecedor nao encontrado." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  std::ofstream outFile("../db.json");
  outFile << db.dump(4);
  outFile.close();
  std::cout << "Número de telefone atualizada com sucesso!" << std::endl;
  ConsoleUtils::pause_and_clear();
}

void VendorService::deleteItem() {}
void VendorService::update() {}

void VendorService::updateEmailVendor()
{
  int stock_id;
  std::string new_location;
  std::string cnpj_vendor, email;
  std::cout << "Informe o CNPJ do Fornecedor que deseja atualizar o email:";
  std::cin >> cnpj_vendor;

  std::ifstream inFile("../db.json");
  if (!inFile.is_open())
  {
    std::cout << "Nao foi possivel abrir o arquivo JSON." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json db;
  inFile >> db;
  inFile.close();

  bool found = false;
  if (db.contains("vendor"))
  {
    for (auto &item : db["vendor"])
    {
      if (item.value("cnpj", "") == cnpj_vendor)
      {
        std::cout << "Informe o endereço de email: ";
        std::cin >> email;
        item["email"] = email;
        found = true;
        break;
      }
    }
  }

  if (!found)
  {
    std::cout << "Fornecedor nao encontrado." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  std::ofstream outFile("../db.json");
  outFile << db.dump(4);
  outFile.close();
  std::cout << "Endereço de email atualizado com sucesso!" << std::endl;
  ConsoleUtils::pause_and_clear();
}