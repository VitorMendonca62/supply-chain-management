/******************************************************************************
 * Arquivo     : user.cpp
 * Autor       : Luís Moreira
 * Criado em   : 29/06/2025
 * Descrição   : Criação do arquivo cpp para a classe User, classe pai envolvendo Usuário
 * 
 * Projeto     : Projeto prático de EDOO
 * 
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Luis)
 ******************************************************************************/
#include "user.h"
#include <iostream>

using namespace std;

bool User::init (const string& i_name, const string& i_password, const string& i_email) {
    if (i_email.find('@') != string::npos) {
        return false;
    }
    name = i_name;
    password = i_password; 
    email = i_email;
    return true;
}

bool User::getAuthorization () { return false; }

// Getters 
string User::getName() const { return name; }
string User::getPassword() const { return password; }
string User::getEmail() const { return email; }

// Setters
void User::setName(const std::string& newName) { name = newName; }
void User::setPassword(const std::string& newPassword) { password = newPassword; }
void User::setEmail(const std::string& newEmail) { email = newEmail; }