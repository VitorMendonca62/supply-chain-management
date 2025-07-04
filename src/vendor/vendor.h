/******************************************************************************
* Arquivo     : vendor.h
 * Autor       : Luís Moreira
 * Criado em   : 15/06/2025
 * Descrição   : Criação do arquivo header para a classe Vendor, referente ao fornecedor
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 * - 15/06/2025: Versão inicial (Luis)
 * - 04/07/2025: Refatorado para seguir o padrão da classe Stock
 ******************************************************************************/

#ifndef VENDOR_H
#define VENDOR_H

#include <iostream>
#include <vector>
#include <string>

class Vendor {
private:
    std::string name;
    std::string cnpj; // Deve ter no máximo 14 caracteres
    std::string phone_number;
    std::string email;
    std::string cep; // Deve ter no máximo 8 caracteres

    // Static member to hold all vendors
    static std::vector<Vendor> vendors;

    bool verifyCep(const std::string&);
    bool verifyCnpj(const std::string&);

public:
    // Constructor
    Vendor(const std::string& name, const std::string& cnpj, const std::string& phone, const std::string& email, const std::string& cep);

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

    // --- Static methods for vendor management ---
    static void createVendor();
    static void listAllVendors();
    static void findVendorByCnpj(); // Using CNPJ as it's more likely to be unique
    static void editVendor();
    static void removeVendor();
};

#endif