/******************************************************************************
 * Arquivo     : vendor_view.h
 * Autor       : Luís Moreira
 * Criado em   : 29/06/2025
 * Descriçao   :
 *   Este arquivo implementa vendor_view.h e printa tudo relacionado ao vendor.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versao inicial (Vitor)
 *  - 04/07/2025: Correções (Luís Moreira)
 ******************************************************************************/

#ifndef VENDOR_VIEW_H
#define VENDOR_VIEW_H

#include "../shared/Menu_view.h"

class VendorView : public MenuView
{
public:
  VendorView() {};
  void print_menu() const override;
  void call_menu_function() const override;
};

#endif