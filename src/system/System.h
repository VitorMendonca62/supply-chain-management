/******************************************************************************
 * Arquivo     : System.h
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo define a classe System, que representa uma view no sistema
 *   de gerenciamento da cadeia de suprimentos.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include "user_view.h"

class System
{
private:
public:
  UserView* print_start() const;
  void print_menu(const UserView &user_view) const;
};
#endif