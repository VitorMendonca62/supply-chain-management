/******************************************************************************
* Arquivo     : stock.h
 * Autor       : Arthur Marinho
 * Criado em   : 17/06/2025
 * Descrição   : Arquivo de cabeçalho para a classe Estoque (versão refatorada).
 * Representa uma linha de inventário (um produto em um local).
 ******************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <vector>

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

    // --- Static methods for stock management ---
    static void createStockItem();
    static void listAllStockItems();
    static void viewStockItemDetails();
    static void updateStockItemQuantity();
    static void updateStockItemLocation();
    static void updateStockItemLastMovementDate();
};

#endif // STOCK_H