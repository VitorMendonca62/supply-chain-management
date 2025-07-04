#include "Stock_service.h"
#include <iostream>
#include "stock.h"
#include "../include/json.hpp"
#include <fstream>

using json = nlohmann::json;

void out_service()
{
    std::cout << "Aperte ENTER para exibir o menu";
    std::cin;
}

void StockService::create()
{
    int stock_id, product_id, quantity;
    std::string location, date;
    std::cout << "Iniciando criação de novo item de estoque...\n";
    std::cout << "Informe o ID do estoque: ";
    std::cin >> stock_id;
    std::cout << "Informe o ID do produto: ";
    std::cin >> product_id;
    std::cout << "Informe a quantidade: ";
    std::cin >> quantity;
    std::cout << "Informe a localização: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, location);
    std::cout << "Informe a data da última movimentação (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    Stock newStock(stock_id, product_id, quantity, location, date);

    json jsonObj = newStock.toJson();

    std::ifstream inFile("../../db.json");
    json db;
    if (inFile.is_open())
    {
        inFile >> db;
        inFile.close();
    }
    else
    {
        db["stock"] = json::array();
    }

    db["stock"].push_back(jsonObj);

    std::ofstream outFile("../../db.json");
    outFile << db.dump(4);
    outFile.close();

    std::cout << "Item de estoque criado em JSON:\n"
              << jsonObj.dump(4) << std::endl;
}

void StockService::getAll()
{
    std::cout << "Exibindo estoque atual...\n";
    std::ifstream inFile("../../db.json");
    if (!inFile.is_open())
    {
        std::cout << "Não foi possível abrir o arquivo de estoque.\n";
        return;
    }

    json db;
    inFile >> db;
    inFile.close();

    if (!db.contains("stock") || db["stock"].empty())
    {
        std::cout << "Nenhum item em estoque.\n";
    }
    else
    {
        for (const auto &item : db["stock"])
        {
            std::cout
                << "=================================\n"
                << "ID do Estoque: " << item.value("stock_id", 0)
                << std::endl
                << ", ID do Produto: " << item.value("product_id", 0)
                << std::endl
                << ", Quantidade: " << item.value("quantity", 0)
                << std::endl
                << ", Localização: " << item.value("location", "")
                << std::endl
                << ", Última Movimentação: " << item.value("last_movement_date", "") << std::endl
                << "=================================\n";
        }
    }
}

void StockService::getOne()
{
    int stock_id;
    std::cout << "Informe o ID do estoque que deseja visualizar:\n";
    std::cin >> stock_id;

    std::ifstream inFile("../../db.json");
    if (!inFile.is_open())
    {
        std::cout << "Não foi possível abrir o arquivo de estoque.\n";
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
                std::cout << "Detalhes do item de estoque:\n";
                std::cout << "  ID do Produto: " << item.value("product_id", 0) << std::endl;
                std::cout << "  Quantidade: " << item.value("quantity", 0) << std::endl;
                std::cout << "  Localização: " << item.value("location", "") << std::endl;
                std::cout << "  Última Movimentação: " << item.value("last_movement_date", "") << std::endl;
                std::cout << "  JSON: " << item.dump(4) << std::endl;
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        std::cout << "Item de estoque não encontrado.\n";
    }
}

void StockService::deleteItem() {}
void StockService::update() {}

void StockService::updateStockItemQuantity()
{
    int stock_id, new_quantity;
    std::cout << "Informe o ID do estoque que deseja atualizar a quantidade:\n";
    std::cin >> stock_id;
    std::cout << "Informe a nova quantidade: ";
    std::cin >> new_quantity;

    std::ifstream inFile("../../db.json");
    if (!inFile.is_open())
    {
        std::cout << "Não foi possível abrir o arquivo de estoque.\n";
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
                item["quantity"] = new_quantity;
                found = true;
                break;
            }
        }
    }

    if (found)
    {
        std::ofstream outFile("../../db.json");
        outFile << db.dump(4);
        outFile.close();
        std::cout << "Quantidade atualizada com sucesso!\n";
    }
    else
    {
        std::cout << "Item de estoque não encontrado.\n";
    }
}

void StockService::updateStockItemLocation()
{
    int stock_id;
    std::string new_location;
    std::cout << "Informe o ID do estoque que deseja atualizar a localização:\n";
    std::cin >> stock_id;
    std::cout << "Informe a nova localização: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, new_location);

    std::ifstream inFile("../../db.json");
    if (!inFile.is_open())
    {
        std::cout << "Não foi possível abrir o arquivo de estoque.\n";
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
                item["location"] = new_location;
                found = true;
                break;
            }
        }
    }

    if (found)
    {
        std::ofstream outFile("../../db.json");
        outFile << db.dump(4);
        outFile.close();
        std::cout << "Localização atualizada com sucesso!\n";
    }
    else
    {
        std::cout << "Item de estoque não encontrado.\n";
    }
}

void StockService::updateStockItemLastMovementDate()
{
    int stock_id;
    std::string new_date;
    std::cout << "Informe o ID do estoque que deseja atualizar a data da última movimentação:\n";
    std::cin >> stock_id;
    std::cout << "Informe a nova data (YYYY-MM-DD): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, new_date);

    std::ifstream inFile("../../db.json");
    if (!inFile.is_open())
    {
        std::cout << "Não foi possível abrir o arquivo de estoque.\n";
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
                item["last_movement_date"] = new_date;
                found = true;
                break;
            }
        }
    }

    if (found)
    {
        std::ofstream outFile("../../db.json");
        outFile << db.dump(4);
        outFile.close();
        std::cout << "Data da última movimentação atualizada com sucesso!\n";
    }
    else
    {
        std::cout << "Item de estoque não encontrado.\n";
    }
}