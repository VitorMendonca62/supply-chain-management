/******************************************************************************
 * Arquivo     : manager.h
 * Autor       : Luís Moreira
 * Criado em   : 29/06/2025
 * Descrição   : Criação do arquivo header para a classe Manager, classe filha de usuário
 * 
 * Projeto     : Projeto prático de EDOO
 * 
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Luis)
 ******************************************************************************/
#ifndef MANAGER_H
#define MANAGER_H
 
#include "../user/user.h"
#include <iostream>

using namespace std;

class Manager : public User {    
    public:           
        bool getAuthorization( ) override;        

};

#endif