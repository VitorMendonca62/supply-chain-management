/******************************************************************************
* Arquivo     : stock.h
 * Autor       : Arthur Marinho
 * Criado em   : 17/06/2025
 * Descriçao   : Arquivo de cabeçalho para a classe Estoque (versao refatorada).
 * Representa uma linha de inventário (um produto em um local).
 ******************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <vector>

#include "../include/json.hpp"
using json = nlohmann::json;


class Stock {
private:
    int stock_id;
    int product_id;
    int quantity;
    std::string stock_location;
    std::string last_movement_date; // Maintained from the StockItem class
    static std::vector<Stock> stock_items;

public:
    // --- Constructor ---
    Stock(int stockId, int productId, int qty, const std::string& location, const std::string& date);

    // --- Destructor ---
    ~Stock();

    // Getters
    int getStockId() const;
    int getProductId() const;
    int getQuantity() const;
    std::string getStockLocation() const;
    std::string getLastMovementDate() const;

    // Setters
    void setQuantity(int new_quantity);
    void setStockLocation(const std::string& new_location);
    void setLastMovementDate(const std::string& new_date);

    json toJson() const;
};
#endif 