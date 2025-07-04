/******************************************************************************
* Arquivo     : stock.cpp
 * Autor       : Arthur Marinho
 * Criado em   : 17/06/2025
 * Descricao   : Arquivo de implementacao para a classe Estoque (versao refatorada).
 ******************************************************************************/

#include "stock.h"
#include <iostream>
#include <limits>
#include "../include/json.hpp"

using json = nlohmann::json;

// --- Constructor Definition ---
Stock::Stock(int stockId, int productId, int qty, const std::string& location, const std::string& date)
    : stock_id(stockId),
      product_id(productId),
      quantity(qty),
      stock_location(location),
      last_movement_date(date) {
    std::cout << "Stock object with ID " << stock_id << " created." << std::endl;
}

// --- Destructor Definition ---
Stock::~Stock() {
    std::cout << "Stock object with ID " << stock_id << " is being destroyed." << std::endl;
}


// --- Getters ---
int Stock::getStockId() const {
    return stock_id;
}

int Stock::getProductId() const {
    return product_id;
}

int Stock::getQuantity() const {
    return quantity;
}

std::string Stock::getStockLocation() const {
    return stock_location;
}

std::string Stock::getLastMovementDate() const {
    return last_movement_date;
}

// --- Setters ---
void Stock::setQuantity(int new_quantity) {
    quantity = new_quantity;
}

void Stock::setStockLocation(const std::string& new_location) {
    stock_location = new_location;
}

void Stock::setLastMovementDate(const std::string& new_date) {
    last_movement_date = new_date;
}

json Stock::toJson() const {
    return json{
        {"stock_id", stock_id},
        {"product_id", product_id},
        {"quantity", quantity},
        {"location", stock_location},
        {"last_movement_date", last_movement_date}
    };
}