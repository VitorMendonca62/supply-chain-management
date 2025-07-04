/******************************************************************************
 * Arquivo     : vendor.cpp
 * Autor       : Luis Moreira
 * Criado em   : 15/06/2025
 * Descricao   : Criacao do arquivo cpp para a classe Vendor, referente ao fornecedor
 *
 * Projeto     : Projeto pratico de EDOO
 *
 * Histórico de Modificacoes:
 *  - 15/06/2025: Versao inicial (Luis)
 *  - 04/07/2025: Ajustes para armazenamento de informacoes no JSON (Luis)
 ******************************************************************************/

#include "vendor.h"
#include <iostream>
#include <limits>
#include "../include/json.hpp"

using json = nlohmann::json;
 


 bool Vendor::init(const std::string& i_name, const std::string& i_cnpj, const std::string& i_tel, const std::string& i_mail, const std::string& i_cep) {
     if (i_name.size() < 1) return false;
     if (i_cep.size() < 1 || i_cep.size() > 8) return false;
 
     name = i_name;
     cnpj = i_cnpj;
     phone_number = i_tel;
     email = i_mail;
     cep = i_cep;
 
     return true;
 }
 
 // Getters 
 std::string Vendor::getName() const { return name; }
 std::string Vendor::getCnpj() const { return cnpj; }
 std::string Vendor::getPhoneNumber() const { return phone_number; }
 std::string Vendor::getEmail() const { return email; }
 std::string Vendor::getCep() const { return cep; }
 
// Setters
void Vendor::setName(const std::string &newName) { name = newName; }
void Vendor::setCnpj(const std::string &newCnpj) { cnpj = newCnpj; }
void Vendor::setPhoneNumber(const std::string &newPhone) { phone_number = newPhone; }
void Vendor::setEmail(const std::string &newEmail) { email = newEmail; }
void Vendor::setCep(const std::string &newCep) { cep = newCep; }

// Metodo do json para retornar os dados do Fornecedor
json Vendor::toJson() const
{
    return json{
        {"name", name},
        {"cnpj", cnpj},
        {"phone_number", phone_number},
        {"email", email},
        {"cep", cep}};
}