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
  switch (action)
  {
  case 1:
    std::cout << "Gerenciando Fornecedores... \n";
    print_vendors_actions();
    break;
  case 2:
    std::cout << "Gerenciando Produtos... \n";
    // Chamar função para gerenciar produtos
    break;
  case 3:
    std::cout << "Gerenciando Estoque... \n";
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

void ManagerView::print_vendors_actions() const
{
  std::cout << "===== Gerenciamento de Fornecedores =====\n";
  std::cout << "Você está no módulo de gerenciamento de fornecedores.\n";
  std::cout << "Aqui você pode adicionar, listar, editar ou remover fornecedores do sistema.\n";
  std::cout << "Escolha uma das opções abaixo:\n";
  std::cout << "1. Adicionar novo fornecedor\n";
  std::cout << "2. Listar todos os fornecedores\n";
  std::cout << "3. Buscar fornecedor por ID\n";
  std::cout << "4. Editar informações de um fornecedor\n";
  std::cout << "5. Remover fornecedor\n";
  std::cout << "6. Voltar ao menu principal\n";
}

void ManagerView::call_vendors_function(int action) const
{
  switch (action)
  {
  case 1:
    std::cout << "Iniciando cadastro de novo fornecedor...\n";
    // Função para adicionar fornecedor
    break;
  case 2:
    std::cout << "Listando todos os fornecedores...\n";
    // Função para listar fornecedores
    break;
  case 3:
    std::cout << "Informe o ID do fornecedor que deseja buscar:\n";
    // Função para buscar fornecedor
    break;
  case 4:
    std::cout << "Informe o ID do fornecedor que deseja editar:\n";
    // Função para editar fornecedor
    break;
  case 5:
    std::cout << "Informe o ID do fornecedor que deseja remover:\n";
    // Função para remover fornecedor
    break;
  case 6:
    std::cout << "Retornando ao menu principal...\n";
    break;
  default:
    std::cout << "Opção inválida. Tente novamente.\n";
  }
}
