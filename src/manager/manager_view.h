/******************************************************************************
 * Arquivo     : Manager_view.h
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo define, a partir de User_view.h, os atributos e métodos
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

#include "../system/user_view.h"

class ManagerView : public UserView
{
public:
  ManagerView() {};
  void print_menu() const override;
  void call_menu_function(int action) const override;
  void print_vendors_actions() const;
  void call_vendors_function(int action) const;
};

#endif