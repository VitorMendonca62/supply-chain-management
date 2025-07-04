/******************************************************************************
 * Arquivo     : Service.h
 * Autor       : Vitor Mendonça
 * Criado em   : 04/07/2025
 * Descrição   :
 *   Define a interface para o menu de gerenciamento de serviços de estoque.
 *
 * Projeto     : Projeto prático de EDOO
 ******************************************************************************/

#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <string>
#include <vector>

class ServiceView {
public:
    ServiceView() = default;

    virtual void create() = 0;

    virtual void getAll() = 0;

    virtual void getOne() = 0;

    virtual void update() = 0;
    
    virtual void deleteItem() = 0;

    virtual ~ServiceView() = default;
};

#endif