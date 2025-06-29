/******************************************************************************
 * Arquivo     : Product.h
 * Autor       : Vitor Mendonça
 * Criado em   : 15/06/2025
 * Descrição   : Criação do arquivo header para a classe Productor, referente ao produto
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 15/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

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
};

#endif