/******************************************************************************
 * Arquivo     : product_view.cpp
 * Autor       : Vitor Mendonca
 * Criado em   : 29/06/2025
 * Descricao   :
 *   Este arquivo implementa User.h e printa tudo relacionado ao produto.
 *
 * Projeto     : Projeto pratico de EDOO
 *
 * Histórico de Modificacoes:
 *  - 29/06/2025: Versao inicial (Vitor)
 ******************************************************************************/

#include <iostream>
#include "product_view.h"
#include "Product_service.h"

ProductService* product_service_in_employee = new ProductService();

void ProductView::print_menu() const
{
  std::cout << "===== Gerenciamento de Produtos =====\n";
  std::cout << "Voce esta no módulo de gerenciamento de produtos.\n";
  std::cout << "Aqui voce pode adicionar, listar, editar ou remover produtos do sistema.\n";
  std::cout << "Escolha uma das opcoes abaixo:\n";
  std::cout << "1. Adicionar novo produto\n";
  std::cout << "2. Listar todos os produtos\n";
  std::cout << "3. Buscar produto por ID\n";
  std::cout << "4. Editar informacoes de um produto\n";
  std::cout << "5. Remover produto\n";
  std::cout << "6. Voltar ao menu principal\n";
}

void ProductView::call_menu_function() const
{
  int action;

  while (action != 6)
  {
    print_menu();
    std::cin >> action;

    switch (action)
    {
    case 1:
      product_service_in_employee->create();      // Funcao para adicionar produto

      break;
    case 2:
      // Funcao para listar produtos
      product_service_in_employee->getAll();
      break;
    case 3:
      // Funcao para buscar produto
      product_service_in_employee->getOne();
      break;
    case 4:
      // Funcao para editar produto
      product_service_in_employee->update();
      break;
    case 5:
      // Funcao para remover produto
      product_service_in_employee->deleteItem();
      break;
    case 6:
      std::cout << "Retornando ao menu principal...\n";
      break;
    default:
      std::cout << "Opcao invalida. Tente novamente.\n";
    }
  }
}
