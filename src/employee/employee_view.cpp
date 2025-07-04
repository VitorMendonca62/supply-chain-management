/******************************************************************************
 * Arquivo     : employee_view.cpp
 * Autor       : Vitor Mendonca
 * Criado em   : 29/06/2025
 * Descricao   :
 *   Este arquivo implementa User.h e printa tudo relacionado ao employee.
 *
 * Projeto     : Projeto pratico de EDOO
 *
 * Histórico de Modificacoes:
 *  - 29/06/2025: Versao inicial (Vitor)
 ******************************************************************************/

#include <iostream>
#include "employee_view.h"

#include "../vendor/vendor_service.h"
#include "../product/Product_service.h"
#include "../stock/Stock_service.h"

void EmployeeView::print_menu() const
{
  std::cout << "Agora voce pode visualizar os itens abaixo.\n";
  std::cout << "O que voce gostaria de fazer?\n";
  std::cout << "1. Listar todos os Fornecedores\n";
  std::cout << "2. Visualizar detalhes de um Fornecedor\n";
  std::cout << "3. Listar todos os Produtos\n";
  std::cout << "4. Visualizar detalhes de um Produto\n";
  std::cout << "5. Listar todos os Estoques\n";
  std::cout << "6. Visualizar detalhes de um Estoque\n";
  std::cout << "7. Sair\n";
}

void EmployeeView::call_menu_function() const
{
  VendorService *vendor_service_in_employee = new VendorService();
  ProductService *product_service_in_employee = new ProductService();
  StockService *stock_service_in_employee = new StockService();

  int action;

  while (true)
  {
    print_menu();
    
    std::cin >> action;

    switch (action)
    {
    case 1:
    {
      vendor_service_in_employee->getAll(); // Lista todos os fornecedores
      break;
    }
    case 2:
    {
      vendor_service_in_employee->getOne(); // Visualiza fornecedor por CNPJ
      break;
    }
    case 3:
    {
      product_service_in_employee->getAll(); // Lista todos os produtos
      break;
    }
    case 4:
    {
      product_service_in_employee->getOne(); // Visualiza produto por ID
      break;
    }
    case 5:
      stock_service_in_employee->getAll();
      break;
    case 6:
      stock_service_in_employee->getOne();
      break;
    case 7:
      std::cout << "Saindo do sistema. Ate logo!\n";
      exit(0);
    default:
      std::cout << "Opcao invalida. Tente novamente.\n";
    }
  }
}