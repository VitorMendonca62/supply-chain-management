/******************************************************************************
 * Arquivo     : Manager_view.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo implementa User.h, chama funções e printa tudo relacionado ao manager.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#include <iostream>
#include "manager_view.h"
#include "../vendor/vendor_view.h"
#include "../product/product_view.h"
#include "../stock/stock_view.h"
#include "../shared/menu_view.h"

void ManagerView::print_menu() const
{
  std::cout << "Agora você pode gerenciar os seguintes itens abaixo. \n";
  std::cout << "O que você gostaria de fazer? \n";
  std::cout << "1. Gerenciar Fornecedores \n";
  std::cout << "2. Gerenciar Produtos \n";
  std::cout << "3. Gerenciar Estoque \n";
  std::cout << "4. Sair \n";
}

void ManagerView::call_menu_function(int action) const
{
  MenuView *viewer;
  switch (action)
  {
  case 1:
    std::cout << "Gerenciando Fornecedores... \n";

    viewer = new VendorView();
    break;
  case 2:
    std::cout << "Gerenciando Produtos... \n";
    viewer = new ProductView();
    // Chamar função para gerenciar produtos
    break;
  case 3:
    std::cout << "Gerenciando Estoque... \n";
    viewer = new StockView();
    // Chamar função para gerenciar estoque
    break;
  case 4:
    std::cout << "Saindo do sistema. Até logo! \n";
    exit(0);
    break;
  default:
    std::cout << "Opção inválida. Tente novamente. \n";
    call_menu_function(action);
    break;
  }

  viewer->print_menu();
  int new_action;
  std::cin >> new_action;
  viewer->call_menu_function(new_action);
}
