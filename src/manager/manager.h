/******************************************************************************
 * Arquivo     : manager.h
 * Autor       : Luís Moreira
 * Criado em   : 29/06/2025
 * Descriçao   : Criaçao do arquivo header para a classe Manager, classe filha de usuário
 * 
 * Projeto     : Projeto prático de EDOO
 * 
 * Histórico de Modificações:
 *  - 29/06/2025: Versao inicial (Luis)
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