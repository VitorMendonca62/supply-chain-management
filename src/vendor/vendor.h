/******************************************************************************
* Arquivo     : vendor.h
 * Autor       : Luís Moreira
 * Criado em   : 15/06/2025
 * Descriçao   : Criaçao do arquivo header para a classe Vendor, referente ao fornecedor
 * 
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 15/06/2025: Versao inicial (Luis)
 *  - 04/07/2025: Ajustes para armazenamento de dados (Luis)
 ******************************************************************************/

 #ifndef VENDOR_H
 #define VENDOR_H
 
 #include <iostream>
 #include <limits>
#include "../include/json.hpp"
using json = nlohmann::json; 

 class Vendor {
     private:
         std::string name;        
         std::string cnpj; // Deve ter no máximo 14 caracteres
         std::string phone_number;
         std::string email;
         std::string cep; // Deve ter no máximo 8 caracteres

     public:
         bool init(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
 
         // Getters
         std::string getName() const;
         std::string getCnpj() const;
         std::string getPhoneNumber() const;
         std::string getEmail() const;
         std::string getCep() const;
 
         // Setters
         void setName(const std::string&);
         void setCnpj(const std::string&);
         void setPhoneNumber(const std::string&);
         void setEmail(const std::string&);
         void setCep(const std::string&);

        // Método especial para armazenamento de informações no JSON
        json toJson() const;
 };
 
 #endif