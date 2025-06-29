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

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    int getWeigth() const;
    std::string getUnitMeasure() const;

    // Setters
    void setName(const std::string &name);
    void setDescription(const std::string &description);
    void setWeigth(int weigth);
    void setUnitMeasure(const std::string &unit_measure);
};

#endif