/******************************************************************************
* Arquivo     : vendor_view.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 * Este arquivo implementa User.h e printa tudo relacionado ao vendor.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 * - 29/06/2025: Versão inicial (Vitor)
 * - 04/07/2025: Refatorado para chamar métodos estáticos da classe Vendor
 ******************************************************************************/

#include <iostream>
#include "vendor_view.h"
#include "vendor.h" // Include Vendor to call its static methods

void VendorView::print_menu() const
{
    std::cout << "===== Gerenciamento de Fornecedores =====\n";
    std::cout << "Você está no módulo de gerenciamento de fornecedores.\n";
    std::cout << "Aqui você pode adicionar, listar, editar ou remover fornecedores do sistema.\n";
    std::cout << "Escolha uma das opções abaixo:\n";
    std::cout << "1. Adicionar novo fornecedor\n";
    std::cout << "2. Listar todos os fornecedores\n";
    std::cout << "3. Buscar fornecedor por CNPJ\n";
    std::cout << "4. Editar informações de um fornecedor\n";
    std::cout << "5. Remover fornecedor\n";
    std::cout << "6. Voltar ao menu principal\n";
}

void VendorView::call_menu_function() const
{
    int action = 0;

    while (action != 6)
    {
        print_menu();
        std::cin >> action;

        switch (action)
        {
            case 1:
                Vendor::createVendor();
                break;
            case 2:
                Vendor::listAllVendors();
                break;
            case 3:
                Vendor::findVendorByCnpj();
                break;
            case 4:
                Vendor::editVendor();
                break;
            case 5:
                Vendor::removeVendor();
                break;
            case 6:
                std::cout << "Retornando ao menu principal...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}