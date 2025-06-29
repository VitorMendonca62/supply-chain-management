/******************************************************************************
 * Arquivo     : user.h
 * Autor       : Luís Moreira
 * Criado em   : 29/06/2025
 * Descrição   : Criação do arquivo header para a classe User, classe pai no que envolve Usuário
 * 
 * Projeto     : Projeto prático de EDOO
 * 
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Luis)
 ******************************************************************************/
#ifndef USER_H
#define USER_H
 
#include <iostream>

using namespace std;

class User {
    private:
        string name;
        string password;
        string email;
    public:
        virtual bool init(const string&, const string&, const string&);
        virtual bool getAuthorization( );

        // Métodos Setters
        void setName(const string&);
        void setPassword(const string&);
        void setEmail(const string&);

        // Método Getters
        string getName() const;
        string getPassword() const;
        string getEmail() const;
        
};

#endif