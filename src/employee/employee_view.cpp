/******************************************************************************
 * Arquivo     : employee_view.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo implementa User.h e printa tudo relacionado ao employee.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#include <iostream>
#include "employee_view.h"

void EmployeeView::print_menu() const
{
  std::cout << "Agora você pode visualizar os itens abaixo. \n";
  std::cout << "O que você gostaria de fazer? \n";
  std::cout << "1. Acessar Fornecedores \n";
  std::cout << "2. Acessar Produtos \n";
  std::cout << "3. Acessar Estoque \n";
  std::cout << "4. Sair \n";
}

void EmployeeView::call_menu_function() const
{
  int action;

  while (true)
  {
    print_menu();
    std::cin >> action;

    switch (action)
    {
    case 1:
      std::cout << "Visualizando Fornecedores... \n";
      // Chamar função para gerenciar fornecedores
      break;
    case 2:
      std::cout << "Visualizando Produtos... \n";
      // Chamar função para gerenciar produtos
      break;
    case 3:
      std::cout << "Visualizando Estoque... \n";
      // Chamar função para gerenciar estoque
      break;
    case 4:
      std::cout << "Saindo do sistema. Até logo! \n";
      exit(0);
      break;
    default:
      std::cout << "Opção inválida. Tente novamente. \n";
    }
  }
}