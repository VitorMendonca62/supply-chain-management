/******************************************************************************
 * Arquivo     : Product.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 15/06/2025
 * Descrição   : Implementação da classe Product, referente ao produto
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Implementando classe (Vitor)
 ******************************************************************************/

#include "Product.h"

// Constructor
Product::init(
    const int i_id,
    const std::string &i_name,
    const std::string &i_description,
    const int i_weigth,
    const std::string &i_unit_measure, )
{
    id = i_id;
    name = i_name;
    description = i_description;
    weigth = i_weigth;
    unit_measure = i_unit_measure;
}

int Product::get_id() const { return id; }

// Name
std::string Product::get_name() const { return name; }

void Product::set_name(const std::string &new_name) { name = new_name; }

// Description
std::string Product::get_description() const { return description; }
void Product::set_description(const std::string &new_description) { description = new_description; }

// Weigth
int Product::get_weigth() const { return weigth; }
void Product::set_weigth(int &new_weigth) { weigth = new_weigth; }

// Unit of measure
std::string Product::get_unit_measure() const { return unit_measure; }
void Product::set_unit_measure(const std::string &new_unit_measure) { unit_measure = new_unit_measure; } 
