/******************************************************************************
 * Arquivo     : User_Printer.h
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo define a classe User_Printer.h.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#ifndef USER_PRINTER_H
#define USER_PRINTER_H

#include <iostream>

class UserPrinter
{
private:
public:
  // Constructor
  UserPrinter() = default;

  void init() const;
  void print_menu() const;
};
#endif