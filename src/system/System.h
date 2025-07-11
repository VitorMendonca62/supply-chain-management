/******************************************************************************
 * Arquivo     : System.h
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descriçao   :
 *   Este arquivo define a classe System, que representa uma view no sistema
 *   de gerenciamento da cadeia de suprimentos.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versao inicial (Vitor)
 ******************************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include "../shared/Menu_view.h"

class System
{
private:
public:
  MenuView* print_start() const;
  void print_menu(const MenuView &menu_view) const;
};
#endif