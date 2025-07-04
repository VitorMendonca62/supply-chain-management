/******************************************************************************
 * Arquivo     : Manager_view.h
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descriçao   :
 *   Este arquivo define, a partir de menu_view.h, os atributos e métodos
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versao inicial (Vitor)
 ******************************************************************************/

#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

#include "../shared/Menu_view.h"

class ManagerView : public MenuView
{
public:
  ManagerView() {};
  void print_menu() const override;
  void call_menu_function() const override;
};

#endif