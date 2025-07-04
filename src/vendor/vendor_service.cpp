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


using json = nlohmann::json;

// Métodos em comum para formatação do conteúdo em terminal
void enter_for_out()
{
#ifdef _WIN32
    _getch();

#else
    std::cin.ignore();
    std::cin.get();
#endif
}

void clear_console()
{
#ifdef _WIN32
    std::system("cls");

#else
    std::system("clear");
#endif
}

void out_service()
{
    std::cout << "Aperte ENTER para exibir o menu ( As mensagens acima serao apagadas)" << std::endl;
    enter_for_out();
    clear_console();
}

void VendorService::create()
{
    std::string name, cnpj, phone_number, email, cep;
    std::cout << "Iniciando criacao de novo fornecedor...";
    std::cout << "Informe o nome do Fornecedor: ";
    std::cin >> name;
    std::cout << "Informe o CNPJ do Fornecedor: ";
    std::cin >> cnpj;
    std::cout << "Informe o número de telefone do Fornecedor: ";
    std::cin >> phone_number;
    std::cout << "Informe o CEP do Fornecedor: ";
    std::cin >> cep;

    Vendor newVendor(name, cnpj, phone_number, email, cep);

    json jsonObj = newVendor.toJson();

    std::ifstream inFile("../db.json");
    if (!inFile.is_open())
    {
        std::cout << "Nao foi possivel abrir o arquivo JSON.";
        out_service();
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

    out_service();
}

void VendorService::getAll()
{
    std::cout << "Exibindo a lista de fornecedores..." << std::endl;
    std::ifstream inFile("../db.json");
    if (!inFile.is_open())
    {
        std::cout << "Nao foi possivel abrir o arquivo JSON.";
        out_service();
        return;
    }

    json db;
    inFile >> db;
    inFile.close();

    if (!db.contains("vendor") || db["vendor"].empty())
    {
        std::cout << "Nenhum Fornecedor criado." << std::endl;
        out_service();
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
        enter_for_out();
    }
    std::cout << "Todos os Fornecedores foram listados" << std::endl;
    out_service();
}

void VendorService::getOne()
{
    std::string vendor_cnpj;
    std::cout << "Informe o CNPJ do Fornecedor que deseja visualizar:";
    std::cin >> vendor_cnpj;

    std::ifstream inFile("../db.json");
    if (!inFile.is_open())
    {
        std::cout << "Nao foi possivel abrir o arquivo JSON.";
        out_service();
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
                          << "   CEP: " << item.value("cep", "") << std::endl
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        std::cout << "Fornecedor nao encontrado." << std::endl;
    }
    out_service();
}

// void VendorService::deleteItem() {}
// void VendorService::update() {}

void VendorService::updatePhoneNumberVendor()
{
    std::string cnpj_vendor, phone_number; 
    std::cout << "Informe o CNPJ do Fornecedor que deseja atualizar o número de telefone:";
    std::cin >> cnpj_vendor;
    std::cout << "Informe o novo número: ";
    std::cin >> phone_number

    std::ifstream inFile("../db.json");
    if (!inFile.is_open())
    {
        std::cout << "Nao foi possivel abrir o arquivo JSON.";
        out_service();
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
                item["phone_number"] = phone_number;
                found = true;
                break;
            }
        }
    }

    if (!found)
    {

        std::cout << "Fornecedor nao encontrado.";
    }

    std::ofstream outFile("../db.json");
    outFile << db.dump(4);
    outFile.close();
    std::cout << "Número de telefone atualizada com sucesso!" << std::endl;
    out_service();
}

void VendorService::updateEmailVendor()
{
    int stock_id;
    std::string new_location;
    std::string cnpj_vendor, email;
    std::cout << "Informe o CNPJ do Fornecedor que deseja atualizar o email:";
    std::cin >> cnpj_vendor;
    std::cout << "Informe o endereço de email: ";
    std::cin >> email;

    std::ifstream inFile("../db.json");
    if (!inFile.is_open())
    {
        std::cout << "Nao foi possivel abrir o arquivo JSON.";
        out_service();
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
                item["email"] = email;
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        std::cout << "Fornecedor nao encontrado.";
    }

    std::ofstream outFile("../db.json");
    outFile << db.dump(4);
    outFile.close();
    std::cout << "Endereço de email atualizado com sucesso!";
    out_service();
}