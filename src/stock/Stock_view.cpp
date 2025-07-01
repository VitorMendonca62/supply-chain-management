/******************************************************************************
 * Arquivo     : Stock_view.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo implementa User.h e printa tudo relacionado ao estoque.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#include <iostream>
#include "stock_view.h"

void StockView::print_menu() const
{
  std::cout << "===== Gerenciamento de Estoque =====\n";
  std::cout << "Você está no módulo de gerenciamento de estoque.\n";
  std::cout << "Aqui você pode visualizar e atualizar o estoque de produtos.\n";
  std::cout << "Escolha uma das opções abaixo:\n";
  std::cout << "1. Visualizar estoque\n";
  std::cout << "2. Adicionar quantidade a um produto\n";
  std::cout << "3. Remover quantidade de um produto\n";
  std::cout << "4. Verificar estoque de um produto específico\n";
  std::cout << "5. Voltar ao menu principal\n";
}

void StockView::call_menu_function() const
{
  int action;

  while (action != 5)
  {
    print_menu();
    std::cin >> action;

    switch (action)
    {
    case 1:
      std::cout << "Exibindo estoque atual...\n";
      // Função para listar estoque
      break;
    case 2:
      std::cout << "Adicionando quantidade a um produto...\n";
      // Função para adicionar ao estoque
      break;
    case 3:
      std::cout << "Removendo quantidade de um produto...\n";
      // Função para remover do estoque
      break;
    case 4:
      std::cout << "Informe o ID do produto que deseja verificar:\n";
      // Função para verificar estoque do produto
      break;
    case 5:
      std::cout << "Retornando ao menu principal...\n";
      break;
    default:
      std::cout << "Opção inválida. Tente novamente.\n";
    }
  }
}
