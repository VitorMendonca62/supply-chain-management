/******************************************************************************
 * Arquivo     : Product.h
 * Autor       : Vitor Mendonça
 * Criado em   : 15/06/2025
 * Descriçao   : Criaçao do arquivo header para a classe Productor, referente ao produto
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 15/06/2025: Versao inicial (Vitor)
 *  - 29/06/2025: Formatando código (Vitor)
 * 
 ******************************************************************************/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

#include "../include/json.hpp"
using json = nlohmann::json;

class Product
{
private:
    int id;
    std::string name;
    std::string description;
    int weigth;
    std::string unit_measure;

public:
    // Construtor
    Product(const int id, const std::string &name, const std::string &description, const int weigth, const std::string &unit_measure);

    int getId() const;

    // Name
    std::string getName() const;
    void setName(const std::string &name);
    
    // Description
    std::string getDescription() const;
    void setDescription(const std::string &description);
    
    // Weight
    void setWeigth(int weigth);
    int getWeigth() const;
    
    // UnitMeasure
    std::string getUnitMeasure() const;
    void setUnitMeasure(const std::string &unit_measure);

    json toJson() const;

};

#endif