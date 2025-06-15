/******************************************************************************
 * Arquivo     : vendor.cpp
 * Autor       : Luís Moreira
 * Criado em   : 15/06/2025
 * Descrição   : Criação do arquivo cpp para a classe Vendor, referente ao fornecedor
 * 
 * Projeto     : Projeto prático de EDOO
 * 
 * Histórico de Modificações:
 *  - 15/06/2025: Versão inicial (Luis)
 ******************************************************************************/

 #define CPPHTTPLIB_OPENSSL_SUPPORT
 #include "httplib.h"
 #include "vendor.h"
 #include <iostream>
 
 bool Vendor::init(const std::string& i_name, const std::string& i_cnpj, const std::string& i_tel, const std::string& i_mail, const std::string& i_cep) {
     if (i_name.size() < 1) return false;
     if (i_cep.size() < 1 || i_cep.size() > 8 || (!this->verifyCep(i_cep))) return false;
 
     name = i_name;
     cnpj = i_cnpj;
     phone_number = i_tel;
     email = i_mail;
     cep = i_cep;
 
     return true;
 }
 
 bool Vendor::verifyCep(const std::string& i_cep) {
     httplib::Client cli("https://brasilapi.com.br");
     auto response = cli.Get("/api/cep/v2/" + i_cep);
 
     return (response && response->status == 200);
 }
 
 // Getters 
 std::string Vendor::getName() const { return name; }
 std::string Vendor::getCnpj() const { return cnpj; }
 std::string Vendor::getPhoneNumber() const { return phone_number; }
 std::string Vendor::getEmail() const { return email; }
 std::string Vendor::getCep() const { return cep; }
 
// Setters
 void Vendor::setName(const std::string& newName) { name = newName; }
 void Vendor::setCnpj(const std::string& newCnpj) { cnpj = newCnpj; }
 void Vendor::setPhoneNumber(const std::string& newPhone) { phone_number = newPhone; }
 void Vendor::setEmail(const std::string& newEmail) { email = newEmail; }
 void Vendor::setCep(const std::string& newCep) { cep = newCep; }
 