/******************************************************************************
 * Arquivo     : vendor_view.cpp
 * Autor       : Vitor Mendonca
 * Criado em   : 29/06/2025
 * Descricao   :
 *   Este arquivo implementa User.h e printa tudo relacionado ao vendor.
 *
 * Projeto     : Projeto pratico de EDOO
 *
 * Histórico de Modificacoes:
 *  - 29/06/2025: Versao inicial (Vitor)
 ******************************************************************************/

#include <iostream>
#include "vendor_view.h"
#include "vendor.h"
#include "vendor_service.h"
#include "../shared/Console_utils.h"

VendorService* vendor_services = new VendorService();



void VendorView::print_menu() const
{
  std::cout << "===== Gerenciamento de Fornecedores =====\n";
  std::cout << "Voce esta no módulo de gerenciamento de fornecedores.\n";
  std::cout << "Aqui voce pode adicionar, listar, editar ou remover fornecedores do sistema.\n";
  std::cout << "Escolha uma das opcoes abaixo:\n";
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
      vendor_services->create( );
      break;
    case 2:
      vendor_services->getAll( );
      break;
    case 3:
      vendor_services->getOne( );
      break;
      case 4:
      vendor_services->updateEmailVendor( );
      // Funcao para editar email de um fornecedor
      break;
      case 5:
      vendor_services->updatePhoneNumberVendor( );
      // Funcao para editar telefone de um fornecedor
      break;
    case 6:
      std::cout << "Retornando ao menu principal...\n";
      ConsoleUtils::clear();
      break;      
      default:
      std::cout << "Opcao invalida. Tente novamente.\n";
      print_menu();
    }
  }
}