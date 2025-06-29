/******************************************************************************
 * Arquivo     : Emplyee.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 *   Este arquivo implementa User.h e printa tudo relacionado ao employee.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 29/06/2025: Versão inicial (Vitor)
 ******************************************************************************/

#include <iostream>
#include <employee_printer.h>
// Constructor
void EmployeePrinter::init()
{
}

void EmployeePrinter::print_menu()
{
  std::cout << "Agora você pode visualizar os itens abaixo. \n";
  std::cout << "O que você gostaria de fazer? \n";
  std::cout << "1. Acessar Fornecedores \n";
  std::cout << "2. Acessar Produtos \n";
  std::cout << "3. Acessar Estoque \n";
  std::cout << "4. Sair \n";
}