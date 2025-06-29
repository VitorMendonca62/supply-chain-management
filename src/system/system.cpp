/******************************************************************************
 * Arquivo     : System.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo implementa a classe System, que representa uma view no sistema
 *   de gerenciamento da cadeia de suprimentos.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#include "System.h"
#include <iostream>

void System::print_start() const
{
  std::cout << "==========================================\n";
  std::cout << " Bem-vindo ao Sistema de Gerenciamento \n";
  std::cout << "==========================================\n";
  std::cout << "Escolha como deseja acessar o sistema:\n";
  std::cout << "1. Acessar como Usuário\n";
  std::cout << "2. Acessar como Gerente\n";
  std::cout << "3. Sair\n";

  int action;
  if (std::cin >> action)
  {
    switch (action)
    {
    case 1:

      std::cout << "Acessando como Usuário...\n";
      // Pedir nome e sennha
      // Onde vai estar armazenado os usuarios?
      break;
    case 2:
    {
      std::cout << "Acessando como Gerente...\n";
      break;
    }
    case 3:
      std::cout << "Encerrando o sistema. Até logo!\n";
      exit(0);
      break;
    default:
      std::cout << "Opção inválida. Tente novamente.\n";
    }
  }
  else
  {
    std::cerr << "Erro ao ler a entrada.\n";
  }
}

void System::print_menu() const
{

  int action;
  if (std::cin >> action)
  {
    switch (action)
    {
    case 1:
      std::cout << "Acessando Fornecedores... \n";
      // Chamar função para gerenciar fornecedores
      break;
    case 2:
      std::cout << "Acessando Produtos... \n";
      // Chamar função para gerenciar produtos
      break;
    case 3:
      std::cout << "Acessando Estoque... \n";
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
  else
  {
    std::cerr << "Erro ao ler a entrada. \n";
  }
}
