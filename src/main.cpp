#include <iostream>
#include <string>
#include <vector>

int main() { // Adicione parênteses aqui
    std::cout << "Bem-vindo ao Sistema de Gerenciamento de Estoque! \n";
    std::cout << "Este é um sistema para gerenciar o estoque de produtos. \n";
    std::cout << "Você pode adicionar, remover e consultar produtos no estoque. \n";
    std::cout << "O que você gostaria de fazer? \n";
    std::cout << "1. Gerenciar Fornecedores \n";
    std::cout << "2. Gerenciar Produtos \n";
    std::cout << "3. Gerenciar Estoque \n";
    std::cout << "4. Sair \n";
    if (std::cin) {
        int opcao;
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Gerenciando Fornecedores... \n";
                // Aqui você pode chamar a função para gerenciar fornecedores
                break;
            case 2:
                std::cout << "Gerenciando Produtos... \n";
                // Aqui você pode chamar a função para gerenciar produtos
                break;
            case 3:
                std::cout << "Gerenciando Estoque... \n";
                // Aqui você pode chamar a função para gerenciar estoque
                break;
            case 4:
                std::cout << "Saindo do sistema. Até logo! \n";
                return 0;
            default:
                std::cout << "Opção inválida. Tente novamente. \n";
        }
    } else {
        std::cerr << "Erro ao ler a entrada. \n";
    }
}