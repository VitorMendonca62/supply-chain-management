/******************************************************************************
 * Arquivo     : Stock_view.cpp
 * Autor       : Vitor Mendonca
 * Criado em   : 29/06/2025
 * Descricao   :
 * Este arquivo implementa User.h e printa tudo relacionado ao estoque.
 *
 * Projeto     : Projeto pratico de EDOO
 *
 * Historico de Modificacoes:
 * - 29/06/2025: Versao inicial (Vitor)
 * - 29/06/2025: Modificado para usar a classe Stock
 * - 29/06/2025: Adicionado menu para cada funcao de stock.cpp
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "stock_view.h"
#include "stock.h"
#include "Stock_service.h"

StockService* stock_service_in_employee = new StockService();

void StockView::print_menu() const
{
  std::cout << "===== Gerenciamento de Estoque =====\n";
  std::cout << "Voce esta no modulo de gerenciamento de estoque.\n";
  std::cout << "Aqui voce pode visualizar e atualizar o estoque de produtos.\n";
  std::cout << "Escolha uma das opcoes abaixo:\n";
  std::cout << "1. Criar novo item de estoque\n";
  std::cout << "2. Listar todos os itens de estoque\n";
  std::cout << "3. Ver detalhes de um item de estoque\n";
  std::cout << "4. Atualizar quantidade de um item de estoque\n";
  std::cout << "5. Atualizar localizacao de um item de estoque\n";
  std::cout << "6. Atualizar data da última movimentacao de um item de estoque\n";
  std::cout << "7. Voltar ao menu principal\n";
}

void StockView::call_menu_function() const {
  int action; // 'action' was passed in, now we declare it inside

  while (action != 7)
  {
    print_menu();
    std::cin >> action;
    switch (action)
    {
      case 1:
        stock_service_in_employee->create();
        break;
      case 2:
        stock_service_in_employee->getAll();
        break;
      case 3:
        stock_service_in_employee->getOne();
        break;
      case 4:
        stock_service_in_employee->updateStockItemQuantity();
        break;
      case 5:
        stock_service_in_employee->updateStockItemLocation();
        break;
      case 6:
        stock_service_in_employee->updateStockItemLastMovementDate();
        break;
      case 7:
        std::cout << "Retornando ao menu principal...\n";
        break;
      default:
        std::cout << "Opcao invalida. Tente novamente.\n";
    }
  }
}