/******************************************************************************
 * Arquivo     : vendor_view.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo implementa User.h e printa tudo relacionado ao vendor.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#include <iostream>
#include "vendor_view.h"
#include "vendor.h"
#include "vendor_service.h"

VendorService* service = new VendorService();



void VendorView::print_menu() const
{
  std::cout << "===== Gerenciamento de Fornecedores =====\n";
  std::cout << "Você está no módulo de gerenciamento de fornecedores.\n";
  std::cout << "Aqui você pode adicionar, listar, editar ou remover fornecedores do sistema.\n";
  std::cout << "Escolha uma das opções abaixo:\n";
  std::cout << "1. Adicionar novo fornecedor\n";
  std::cout << "2. Listar todos os fornecedores\n";
  std::cout << "3. Buscar fornecedor por ID\n";
  std::cout << "4. Atualizar email de um fornecedor\n";
  std::cout << "5. Atualizar telefone de um fornecedor\n";
  std::cout << "6. Voltar ao menu principal\n";
}

void VendorView::call_menu_function() const
{
  int action;

  while (action != 6)
  {
    print_menu();
    std::cin >> action;

    switch (action)
    {
    case 1:
      std::cout << "Iniciando cadastro de novo fornecedor...\n";
      service->create( );
      break;
    case 2:
      std::cout << "Listando todos os fornecedores...\n";
      service->getAll( );
      break;
    case 3:
      std::cout << "Informe o ID do fornecedor que deseja buscar:\n";
      service->getOne( );
      break;
    case 4:
      std::cout << "Informe o ID do fornecedor que deseja editar:\n";
      // Função para editar email de um fornecedor
      break;
    case 5:
      std::cout << "Informe o ID do fornecedor que deseja remover:\n";
      // Função para editar telefone de um fornecedor
      break;
    case 6:
      std::cout << "Retornando ao menu principal...\n";
      break;      
    default:
      std::cout << "Opção inválida. Tente novamente.\n";
    }
  }
}