/******************************************************************************
 * Arquivo     : Menu_view.h
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo define a classe Menu_view.h.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <iostream>

class MenuView
{
private:
public:
  // Constructor
  MenuView() = default;

  virtual void print_menu() const = 0;
  virtual void call_menu_function(int action) const = 0;
};
#endif