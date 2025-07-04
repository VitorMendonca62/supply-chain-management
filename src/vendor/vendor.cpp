/******************************************************************************
 * Arquivo     : vendor.cpp
 * Autor       : Luís Moreira
 * Criado em   : 15/06/2025
 * Descrição   : Criação do arquivo cpp para a classe Vendor, referente ao fornecedor
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 * - 15/06/2025: Versão inicial (Luis)
 * - 04/07/2025: Refatorado para seguir o padrão da classe Stock
 ******************************************************************************/

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "vendor.h"
#include <iostream>
#include <limits>

// Initialize the static vendors vector
std::vector<Vendor> Vendor::vendors;

// --- Constructor Definition ---
Vendor::Vendor(const std::string& i_name, const std::string& i_cnpj, const std::string& i_tel, const std::string& i_mail, const std::string& i_cep)
{
    name = i_name;
    cnpj = i_cnpj;
    phone_number = i_tel;
    email = i_mail;
    cep = i_cep;
}

bool Vendor::verifyCep(const std::string& i_cep) {
    httplib::Client cli("https://brasilapi.com.br");
    auto response = cli.Get("/api/cep/v2/" + i_cep);
    return (response && response->status == 200);
}

// --- Getters ---
std::string Vendor::getName() const { return name; }
std::string Vendor::getCnpj() const { return cnpj; }
std::string Vendor::getPhoneNumber() const { return phone_number; }
std::string Vendor::getEmail() const { return email; }
std::string Vendor::getCep() const { return cep; }

// --- Setters ---
void Vendor::setName(const std::string& newName) { name = newName; }
void Vendor::setCnpj(const std::string& newCnpj) { cnpj = newCnpj; }
void Vendor::setPhoneNumber(const std::string& newPhone) { phone_number = newPhone; }
void Vendor::setEmail(const std::string& newEmail) { email = newEmail; }
void Vendor::setCep(const std::string& newCep) { cep = newCep; }

// --- Static methods for vendor management ---
void Vendor::createVendor() {
    std::string name, cnpj, phone, email, cep;

    std::cout << "Iniciando cadastro de novo fornecedor...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer

    std::cout << "Nome do Fornecedor: ";
    std::getline(std::cin, name);
    std::cout << "CNPJ do Fornecedor: ";
    std::getline(std::cin, cnpj);
    std::cout << "Telefone do Fornecedor: ";
    std::getline(std::cin, phone);
    std::cout << "Email do Fornecedor: ";
    std::getline(std::cin, email);
    std::cout << "CEP do Fornecedor: ";
    std::getline(std::cin, cep);

    // Basic Validation (can be improved)
    if (name.empty() || cnpj.empty() || cep.empty()) {
        std::cout << "Nome, CNPJ e CEP são campos obrigatórios. Cadastro cancelado.\n";
        return;
    }

    vendors.emplace_back(name, cnpj, phone, email, cep);
    std::cout << "Fornecedor cadastrado com sucesso!\n";
}

void Vendor::listAllVendors() {
    std::cout << "Exibindo todos os fornecedores...\n";
    if (vendors.empty()) {
        std::cout << "Nenhum fornecedor cadastrado.\n";
    } else {
        for (const auto& vendor : vendors) {
            std::cout << "Nome: " << vendor.getName()
                      << ", CNPJ: " << vendor.getCnpj()
                      << ", Telefone: " << vendor.getPhoneNumber() << std::endl;
        }
    }
}

// Other static functions would be implemented similarly
void Vendor::findVendorByCnpj() {
    std::cout << "Funcionalidade de busca ainda não implementada.\n";
}

void Vendor::editVendor() {
    std::cout << "Funcionalidade de edição ainda não implementada.\n";
}

void Vendor::removeVendor() {
    std::cout << "Funcionalidade de remoção ainda não implementada.\n";
}