/******************************************************************************
 * Arquivo     : User_View.h
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo define a classe User_View.h.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#ifndef USER_VIEW_H
#define USER_VIEW_H

#include <iostream>

class UserView
{
private:
public:
  // Constructor
  UserView() = default;

  virtual void print_menu() const = 0;
  virtual void call_menu_function(int action) const = 0;
};
#endif