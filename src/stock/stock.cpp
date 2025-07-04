/******************************************************************************
* Arquivo     : stock.cpp
 * Autor       : Arthur Marinho
 * Criado em   : 17/06/2025
 * Descrição   : Arquivo de implementação para a classe Estoque (versão refatorada).
 ******************************************************************************/

#include "stock.h"
#include <iostream>
#include <limits>

// Initialize the static stock_items vector
std::vector<Stock> Stock::stock_items;

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

// --- Static methods for stock management ---
void Stock::createStockItem() {
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

    stock_items.emplace_back(stock_id, product_id, quantity, location, date);
    std::cout << "Item de estoque criado com sucesso!\n";
}

void Stock::listAllStockItems() {
    std::cout << "Exibindo estoque atual...\n";
    if (stock_items.empty()) {
        std::cout << "Nenhum item em estoque.\n";
    } else {
        for (const auto& item : stock_items) {
            std::cout << "ID do Estoque: " << item.getStockId()
                      << ", ID do Produto: " << item.getProductId()
                      << ", Quantidade: " << item.getQuantity()
                      << ", Localização: " << item.getStockLocation()
                      << ", Última Movimentação: " << item.getLastMovementDate() << std::endl;
        }
    }
}

void Stock::viewStockItemDetails() {
    int stock_id;
    std::cout << "Informe o ID do estoque que deseja visualizar:\n";
    std::cin >> stock_id;
    bool found = false;
    for (const auto& item : stock_items) {
        if (item.getStockId() == stock_id) {
            std::cout << "Detalhes do item de estoque:\n";
            std::cout << "  ID do Produto: " << item.getProductId() << std::endl;
            std::cout << "  Quantidade: " << item.getQuantity() << std::endl;
            std::cout << "  Localização: " << item.getStockLocation() << std::endl;
            std::cout << "  Última Movimentação: " << item.getLastMovementDate() << std::endl;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Item de estoque não encontrado.\n";
    }
}

void Stock::updateStockItemQuantity() {
    int stock_id, new_quantity;
    std::cout << "Informe o ID do estoque que deseja atualizar a quantidade:\n";
    std::cin >> stock_id;
    std::cout << "Informe a nova quantidade: ";
    std::cin >> new_quantity;
    bool found = false;
    for (auto& item : stock_items) {
        if (item.getStockId() == stock_id) {
            item.setQuantity(new_quantity);
            std::cout << "Quantidade atualizada com sucesso!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Item de estoque não encontrado.\n";
    }
}

void Stock::updateStockItemLocation() {
    int stock_id;
    std::string new_location;
    std::cout << "Informe o ID do estoque que deseja atualizar a localização:\n";
    std::cin >> stock_id;
    std::cout << "Informe a nova localização: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, new_location);
    bool found = false;
    for (auto& item : stock_items) {
        if (item.getStockId() == stock_id) {
            item.setStockLocation(new_location);
            std::cout << "Localização atualizada com sucesso!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Item de estoque não encontrado.\n";
    }
}

void Stock::updateStockItemLastMovementDate() {
    int stock_id;
    std::string new_date;
    std::cout << "Informe o ID do estoque que deseja atualizar a data da última movimentação:\n";
    std::cin >> stock_id;
    std::cout << "Informe a nova data (YYYY-MM-DD): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, new_date);
    bool found = false;
    for (auto& item : stock_items) {
        if (item.getStockId() == stock_id) {
            item.setLastMovementDate(new_date);
            std::cout << "Data da última movimentação atualizada com sucesso!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Item de estoque não encontrado.\n";
    }
}