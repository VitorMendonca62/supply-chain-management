/******************************************************************************
* Arquivo     : Product.cpp
 * Autor       : Vitor Mendonca
 * Criado em   : 15/06/2025
 * Descricao   : Implementacao da classe Product, referente ao produto
 *
 * Projeto     : Projeto pratico de EDOO
 *
 * Histórico de Modificacoes:
 * - 29/06/2025: Implementando classe (Vitor)
 ******************************************************************************/

#include "Product.h"

Product::Product(
    const int i_id,
    const std::string &i_name,
    const std::string &i_description,
    const int i_weigth,
    const std::string &i_unit_measure)
{
    id = i_id;
    name = i_name;
    description = i_description;
    weigth = i_weigth;
    unit_measure = i_unit_measure;
}

int Product::getId() const { return id; }

// Name
std::string Product::getName() const { return name; }

void Product::setName(const std::string &new_name) { name = new_name; }

// Description
std::string Product::getDescription() const { return description; }

void Product::setDescription(const std::string &new_description) { description = new_description; }

// Weigth
int Product::getWeigth() const { return weigth; }

void Product::setWeigth(int new_weigth) { weigth = new_weigth; }

// Unit of measure
std::string Product::getUnitMeasure() const { return unit_measure; }

void Product::setUnitMeasure(const std::string &new_unit_measure) { unit_measure = new_unit_measure; }

// Metodo do json para retornar os dados do Produto
json Product::toJson() const
{
    return json{
        {"name", name},
        {"id", id},
        {"description", description},
        {"weigth", weigth},
        {"unit_measure", unit_measure}};
}