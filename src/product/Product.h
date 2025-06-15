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


class Product {
private:
    int _id;
    std::string _name;
    std::string _description;
    int _weigth;
    std::string _unit_measure;

public:
    // Constructor 
    Product(
      const int id,
      const std::string& name,
      const std::string& description,
      const int weigth,
      const std::string& unit_measure)
      :
      _id(id),
      _name(name),
      _description(description),
      _weigth(weigth),
      _unit_measure(unit_measure) {}

    // ID
    int get_id() const {
        return _id;
    }

    // Name
    std::string get_name() const {
        return _name;
    }

    void set_name(const std::string& name) {
        _name = name;
    }

    // Description
    std::string get_description() const {
        return _description;
    }

    void set_description(const std::string& description) {
        _description = description;
    }

    // Weigth
    int get_weigth() const {
        return _weigth;
    }

    void set_weigth(int weigth) {
        _weigth = weigth;
    }

    // Unit of measure
    std::string get_unitMeasure() const {
        return _unit_measure;
    }

    void set_unitMeasure(const std::string& unit_measure) {
        _unit_measure = unit_measure;
    }
};
#endif