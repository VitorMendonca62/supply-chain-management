/******************************************************************************
 * Arquivo     : Manager.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo implementa User.h e printa tudo relacionado ao manager.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#include <iostream>
#include <manager_printer.h>

// Constructor
void ManagerPrinter::init()
{
}

void ManagerPrinter::print_menu()
{
  std::cout << "Agora ocê pode adicionar, remover e consultar produtos no estoque. \n";
  std::cout << "O que você gostaria de fazer? \n";
  std::cout << "1. Gerenciar Fornecedores \n";
  std::cout << "2. Gerenciar Produtos \n";
  std::cout << "3. Gerenciar Estoque \n";
  std::cout << "4. Sair \n";
}