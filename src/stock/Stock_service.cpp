
#include "Stock_service.h"
#include <iostream>
#include "stock.h"
#include "../include/json.hpp"
#include <fstream>
#include <conio.h>
#include "../shared/Console_utils.h"

using json = nlohmann::json;

void StockService::create()
{
    int stock_id, product_id, quantity;
    std::string location, date;
    std::cout << "Iniciando criacao de novo item de estoque..." << std::endl;
    std::cout << "Informe o ID do estoque: ";
    std::cin >> stock_id;
    std::cout << "Informe o ID do produto: ";
    std::cin >> product_id;
    std::cout << "Informe a quantidade: ";
    std::cin >> quantity;
    std::cout << "Informe a localizacao: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, location);
    std::cout << "Informe a data da ultima movimentacao (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    Stock newStock(stock_id, product_id, quantity, location, date);

    json jsonObj = newStock.toJson();

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

    db["stock"].push_back(jsonObj);

    std::ofstream outFile("../db.json");
    outFile << db.dump(4);
    outFile.close();

    std::cout << "Item de estoque criado com sucesso!" << std::endl;

    ConsoleUtils::pause_and_clear();
}

void StockService::getAll()
{
    std::cout << "Exibindo estoque atual..." << std::endl;
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

    if (!db.contains("stock") || db["stock"].empty())
    {
        std::cout << "Nenhum item em estoque." << std::endl;
        ConsoleUtils::pause_and_clear();
        return;
    }
    for (const auto &item : db["stock"])
    {
        std::cout
            << "================================="
            << std::endl
            << "   ID do Estoque: " << item.value("stock_id", 0)
            << std::endl
            << "   Quantidade: " << item.value("quantity", 0)
            << std::endl
            << "   Localizacao: " << item.value("location", "")
            << std::endl
            << "   Ultima Movimentacao: " << item.value("last_movement_date", "") << std::endl
            << "================================="
            << std::endl;
        std::cout << "Aperte ENTER para o proximo item" << std::endl;
        ConsoleUtils::wait_for_enter();
    }
    std::cout << "Todos os itens foram listados" << std::endl;
    ConsoleUtils::pause_and_clear();
}

void StockService::getOne()
{
    int stock_id;
    std::cout << "Informe o ID do estoque que deseja visualizar: ";
    std::cin >> stock_id;

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

    bool found = false;
    if (db.contains("stock"))
    {
        for (const auto &item : db["stock"])
        {
            if (item.value("stock_id", 0) == stock_id)
            {
                std::cout << "Detalhes do item de estoque:"
                          << std::endl
                          << "  ID do Produto: " << item.value("product_id", 0)
                          << std::endl
                          << "  Quantidade: " << item.value("quantity", 0)
                          << std::endl
                          << "  Localizacao: " << item.value("location", "")
                          << std::endl
                          << "  Ultima Movimentacao: " << item.value("last_movement_date", "")
                          << std::endl;
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        std::cout << "Item de estoque nao encontrado." << std::endl;
        ConsoleUtils::pause_and_clear();
        return;
    }
    ConsoleUtils::pause_and_clear();
}

void StockService::deleteItem() {}
void StockService::update() {}

void StockService::updateStockItemQuantity()
{
    int stock_id, new_quantity;
    std::cout << "Informe o ID do estoque que deseja atualizar a quantidade:";
    std::cin >> stock_id;

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

    bool found = false;
    if (db.contains("stock"))
    {
        for (auto &item : db["stock"])
        {
            if (item.value("stock_id", 0) == stock_id)
            {
                std::cout << "Informe a nova quantidade: ";
                std::cin >> new_quantity;

                item["quantity"] = new_quantity;
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        std::cout << "Item de estoque nao encontrado." << std::endl;
        ConsoleUtils::pause_and_clear();
        return;
    }

    std::ofstream outFile("../db.json");
    outFile << db.dump(4);
    outFile.close();
    std::cout << "Quantidade atualizada com sucesso!" << std::endl;
    ConsoleUtils::pause_and_clear();
}

void StockService::updateStockItemLocation()
{
    int stock_id;
    std::string new_location;
    std::cout << "Informe o ID do estoque que deseja atualizar a localizacao:";
    std::cin >> stock_id;

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

    bool found = false;
    if (db.contains("stock"))
    {
        for (auto &item : db["stock"])
        {
            if (item.value("stock_id", 0) == stock_id)
            {
                std::cout << "Informe a nova localizacao: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, new_location);
                item["location"] = new_location;
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        std::cout << "Item de estoque nao encontrado." << std::endl;
        ConsoleUtils::pause_and_clear();
        return;
    }

    std::ofstream outFile("../db.json");
    outFile << db.dump(4);
    outFile.close();
    std::cout << "Localizacao atualizada com sucesso!" << std::endl;
    ConsoleUtils::pause_and_clear();
}

void StockService::updateStockItemLastMovementDate()
{
    int stock_id;
    std::string new_date;
    std::cout << "Informe o ID do estoque que deseja atualizar a data da ultima movimentacao:";
    std::cin >> stock_id;

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

    bool found = false;
    if (db.contains("stock"))
    {
        for (auto &item : db["stock"])
        {
            if (item.value("stock_id", 0) == stock_id)
            {
                std::cout << "Informe a nova data (YYYY-MM-DD): ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, new_date);

                item["last_movement_date"] = new_date;
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        std::cout << "Item de estoque nao encontrado." << std::endl;
        ConsoleUtils::pause_and_clear(); return;
    }

    std::ofstream outFile("../db.json");
    outFile << db.dump(4);
    outFile.close();
    std::cout << "Data da ultima movimentacao atualizada com sucesso!" << std::endl;
    ConsoleUtils::pause_and_clear();
}
