/******************************************************************************
 * Arquivo     : Estoque.cpp
 * Autor       : Arthur Marinho
 * Criado em   : 17/06/2025
 * Descrição   : Arquivo de implementação para a classe Estoque (versão refatorada).
 ******************************************************************************/

#include "stock.h"

// --- Definições dos Métodos da Classe Estoque ---


bool Stock::init(int stockId, int productId, int qty, const std::string& location, const std::string& date) {
    stock_id = stockId;
    product_id = productId;
    quantity = qty;
    stock_location = location;
    last_movement_date = date;
    return true;
}

// Getters
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

// Setters
void Stock::setQuantity(int new_quantity) {
    quantity = new_quantity;
}

void Stock::setStockLocation(const std::string& new_location) {
    stock_location = new_location;
}

void Stock::setLastMovementDate(const std::string& new_date) {
    last_movement_date = new_date;
}