/******************************************************************************
 * Arquivo     : product_view.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo implementa User.h e printa tudo relacionado ao produto.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#include <iostream>
#include "product_view.h"

void ProductView::print_menu() const
{
  std::cout << "===== Gerenciamento de Produtos =====\n";
  std::cout << "Você está no módulo de gerenciamento de produtos.\n";
  std::cout << "Aqui você pode adicionar, listar, editar ou remover produtos do sistema.\n";
  std::cout << "Escolha uma das opções abaixo:\n";
  std::cout << "1. Adicionar novo produto\n";
  std::cout << "2. Listar todos os produtos\n";
  std::cout << "3. Buscar produto por ID\n";
  std::cout << "4. Editar informações de um produto\n";
  std::cout << "5. Remover produto\n";
  std::cout << "6. Voltar ao menu principal\n";
}

void ProductView::call_menu_function(int action) const
{
  switch (action)
  {
  case 1:
    std::cout << "Iniciando cadastro de novo produto...\n";
    // Função para adicionar produto
    break;
  case 2:
    std::cout << "Listando todos os produtos...\n";
    // Função para listar produtos
    break;
  case 3:
    std::cout << "Informe o ID do produto que deseja buscar:\n";
    // Função para buscar produto
    break;
  case 4:
    std::cout << "Informe o ID do produto que deseja editar:\n";
    // Função para editar produto
    break;
  case 5:
    std::cout << "Informe o ID do produto que deseja remover:\n";
    // Função para remover produto
    break;
  case 6:
    std::cout << "Retornando ao menu principal...\n";
    break;
  default:
    std::cout << "Opção inválida. Tente novamente.\n";
  }
}
