/******************************************************************************
 * Arquivo     : System.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo implementa a classe System, que representa uma view no sistema
 *   de gerenciamento da cadeia de suprimentos.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#include "System.h"
#include <iostream>
#include "../shared/Menu_view.h"
#include "../manager/manager_view.h"
#include "../employee/employee_view.h"

MenuView *System::print_start() const
{
  std::cout << "==========================================\n";
  std::cout << " Bem-vindo ao Sistema de Gerenciamento \n";
  std::cout << "==========================================\n";
  std::cout << "Escolha como deseja acessar o sistema:\n";
  std::cout << "1. Acessar como Funcionario\n";
  std::cout << "2. Acessar como Gerente\n";
  std::cout << "3. Sair\n";

  int action;
  if (std::cin >> action)
  {
    switch (action)
    {
    case 1:
      std::cout << "Acessando como Funcionario...\n";
      // Pedir nome e sennha
      // Onde vai estar armazenado os usuarios?
      return new EmployeeView();
    case 2:
      std::cout << "Acessando como Gerente...\n";
      return new ManagerView();

    case 3:
      std::cout << "Encerrando o sistema. Até logo!\n";
      exit(0);
    default:
      std::cout << "Opção inválida. Tente novamente.\n";
      return print_start();
    }
  }
  else
  {
    std::cerr << "Erro ao ler a entrada.\n";
    return print_start();
  }
}

void System::print_menu(const MenuView &menu_view) const
{
  menu_view.print_menu();
  int action;
  std::cin >> action;
  menu_view.call_menu_function(action);


}
