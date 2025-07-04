#include "Product_service.h"
#include "./Product.h"
#include "../shared/Console_utils.h"
#include "../include/json.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;

void ProductService::create()
{
  std::string name, description, unit_measure;
  int id;
  int weigth;

  std::cout << "Iniciando criacao de novo produto..." << std::endl;
  std::cout << "Informe o id do produto: ";
  std::cin >> id;
  std::cout << "Informe o nome do produto: ";
  std::cin >> name;
  std::cout << "Informe a descricao do produto: ";
  std::cin >> description;
  std::cout << "Informe o peso do produto (inteiro): ";
  std::cin >> weigth;
  std::cout << "Informe a unidade de medida: ";
  std::cin >> unit_measure;

  Product product(id, name, description, weigth, unit_measure);

  json productJson = product.toJson();

  std::ifstream inFile("../db.json");
  if (!inFile.is_open())
  {
    std::cout << "Nao foi possivel abrir o arquivo de estoque." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json db;
  inFile >> db;
  inFile.close();
  db["product"].push_back(productJson);

  std::ofstream outFile("../db.json");
  outFile << db.dump(4);
  outFile.close();

  std::cout << "Produto criado com sucesso!" << std::endl;
  ConsoleUtils::pause_and_clear();
}

void ProductService::getAll()
{
  std::ifstream inFile("../db.json");
  if (!inFile.is_open())
  {
    std::cout << "Erro ao abrir o arquivo de produtos." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json db;
  inFile >> db;
  inFile.close();

  if (!db.contains("product") || db["product"].empty())
  {
    std::cout << "Nenhum produto encontrado." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  for (const auto &item : db["product"])
  {
    std::cout << "ID: " << item.value("id", 0)
              << "\nNome: " << item.value("name", "")
              << "\nDescricao: " << item.value("description", "")
              << "\nPeso: " << item.value("weigth", 0)
              << "\nUnidade de medida: " << item.value("unit_measure", "")
              << "\n----------------------------\n";
    std::cout << "Aperte ENTER para o proximo item" << std::endl;
    ConsoleUtils::wait_for_enter();
  }

  ConsoleUtils::pause_and_clear();
}

void ProductService::getOne()
{
  int id;
  std::cout << "Informe o ID do produto: ";
  std::cin >> id;

  std::ifstream inFile("../db.json");
  if (!inFile.is_open())
  {
    std::cout << "Erro ao abrir o arquivo de produtos." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json db;
  inFile >> db;
  inFile.close();

  if (!db.contains("product"))
  {
    std::cout << "Nenhum produto encontrado." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  for (const auto &item : db["product"])
  {
    if (item.value("id", 0) == id)
    {
      std::cout << "Produto encontrado:"
                << "\nNome: " << item.value("name", "")
                << "\nDescricao: " << item.value("description", "")
                << "\nPeso: " << item.value("weigth", 0)
                << "\nUnidade de medida: " << item.value("unit_measure", "")
                << std::endl;
      ConsoleUtils::pause_and_clear();
      return;
    }
  }

  std::cout << "Produto nao encontrado." << std::endl;
  ConsoleUtils::pause_and_clear();
}

void ProductService::update()
{
  int id;
  std::cout << "Informe o ID do produto que deseja atualizar: ";
  std::cin >> id;

  std::ifstream inFile("../db.json");
  if (!inFile.is_open())
  {
    std::cout << "Erro ao abrir o arquivo." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json db;
  inFile >> db;
  inFile.close();

  bool found = false;
  for (auto &item : db["product"])
  {
    if (item.value("id", 0) == id)
    {
      std::string name, description, unit_measure;
      int weigth;

      std::cout << "Novo nome: ";
      std::cin >> name;
      std::cout << "Nova descricao: ";
      std::cin >> description;
      std::cout << "Novo peso: ";
      std::cin >> weigth;
      std::cout << "Nova unidade de medida: ";
      std::cin >> unit_measure;

      item["name"] = name;
      item["description"] = description;
      item["weigth"] = weigth;
      item["unit_measure"] = unit_measure;

      found = true;
      break;
    }
  }

  if (!found)
  {
    std::cout << "Produto nao encontrado." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  std::ofstream outFile("../db.json");
  outFile << db.dump(4);
  outFile.close();

  std::cout << "Produto atualizado com sucesso!" << std::endl;
  ConsoleUtils::pause_and_clear();
}

void ProductService::deleteItem()
{
  int id;
  std::cout << "Informe o ID do produto que deseja remover: ";
  std::cin >> id;

  std::ifstream inFile("../db.json");
  if (!inFile.is_open())
  {
    std::cout << "Erro ao abrir o arquivo." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  json db;
  inFile >> db;
  inFile.close();

  if (!db.contains("product"))
  {
    std::cout << "Nenhum produto cadastrado." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  auto &products = db["product"];
  auto it = std::remove_if(products.begin(), products.end(), [&](const json &item)
                           { return item.value("id", 0) == id; });

  if (it == products.end())
  {
    std::cout << "Produto nao encontrado." << std::endl;
    ConsoleUtils::pause_and_clear();
    return;
  }

  products.erase(it, products.end());

  std::ofstream outFile("../db.json");
  outFile << db.dump(4);
  outFile.close();

  std::cout << "Produto removido com sucesso!" << std::endl;
  ConsoleUtils::pause_and_clear();
}
