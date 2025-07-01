/******************************************************************************
 * Arquivo     : Stock_view.cpp
 * Autor       : Vitor Mendonça
 * Criado em   : 29/06/2025
 * Descrição   :
 * Este arquivo implementa User.h e printa tudo relacionado ao estoque.
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 * - 29/06/2025: Versão inicial (Vitor)
 * - 29/06/2025: Modificado para usar a classe Stock (Gemini)
 * - 29/06/2025: Adicionado menu para cada função de stock.cpp (Gemini)
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "stock_view.h"
#include "stock.h"

// Vetor para armazenar o estoque
std::vector<Stock> stock_items;

void StockView::print_menu() const
{
  std::cout << "===== Gerenciamento de Estoque =====\n";
  std::cout << "Você está no módulo de gerenciamento de estoque.\n";
  std::cout << "Aqui você pode visualizar e atualizar o estoque de produtos.\n";
  std::cout << "Escolha uma das opções abaixo:\n";
  std::cout << "1. Criar novo item de estoque\n";
  std::cout << "2. Listar todos os itens de estoque\n";
  std::cout << "3. Ver detalhes de um item de estoque\n";
  std::cout << "4. Atualizar quantidade de um item de estoque\n";
  std::cout << "5. Atualizar localização de um item de estoque\n";
  std::cout << "6. Atualizar data da última movimentação de um item de estoque\n";
  std::cout << "7. Voltar ao menu principal\n";
}

void StockView::call_menu_function() const
{
  int action;

  while (action != 5)
  {
    print_menu();
    std::cin >> action;

    switch (action)
    {
    case 1:
    {
      int stock_id, product_id, quantity;
      std::string location, date;
      std::cout << "Iniciando criação de novo item de estoque...\n";
      std::cout << "Informe o ID do estoque: ";
      std::cin >> stock_id;
      std::cout << "Informe o ID do produto: ";
      std::cin >> product_id;
      std::cout << "Informe a quantidade: ";
      std::cin >> quantity;
      std::cout << "Informe a localização: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, location);
      std::cout << "Informe a data da última movimentação (YYYY-MM-DD): ";
      std::getline(std::cin, date);

      stock_items.emplace_back(stock_id, product_id, quantity, location, date);
      std::cout << "Item de estoque criado com sucesso!\n";
    }
    break;
    case 2:
      std::cout << "Exibindo estoque atual...\n";
      if (stock_items.empty())
      {
        std::cout << "Nenhum item em estoque.\n";
      }
      else
      {
        for (const auto &item : stock_items)
        {
          std::cout << "ID do Estoque: " << item.getStockId()
                    << ", ID do Produto: " << item.getProductId()
                    << ", Quantidade: " << item.getQuantity()
                    << ", Localização: " << item.getStockLocation()
                    << ", Última Movimentação: " << item.getLastMovementDate() << std::endl;
        }
      }
      break;
    case 3:
    {
      int stock_id;
      std::cout << "Informe o ID do estoque que deseja visualizar:\n";
      std::cin >> stock_id;
      bool found = false;
      for (const auto &item : stock_items)
      {
        if (item.getStockId() == stock_id)
        {
          std::cout << "Detalhes do item de estoque:\n";
          std::cout << "  ID do Produto: " << item.getProductId() << std::endl;
          std::cout << "  Quantidade: " << item.getQuantity() << std::endl;
          std::cout << "  Localização: " << item.getStockLocation() << std::endl;
          std::cout << "  Última Movimentação: " << item.getLastMovementDate() << std::endl;
          found = true;
          break;
        }
      }
      if (!found)
      {
        std::cout << "Item de estoque não encontrado.\n";
      }
    }
    break;
    case 4:
    {
      int stock_id, new_quantity;
      std::cout << "Informe o ID do estoque que deseja atualizar a quantidade:\n";
      std::cin >> stock_id;
      std::cout << "Informe a nova quantidade: ";
      std::cin >> new_quantity;
      bool found = false;
      for (auto &item : stock_items)
      {
        if (item.getStockId() == stock_id)
        {
          item.setQuantity(new_quantity);
          std::cout << "Quantidade atualizada com sucesso!\n";
          found = true;
          break;
        }
      }
      if (!found)
      {
        std::cout << "Item de estoque não encontrado.\n";
      }
    }
    break;
    case 5:
    {
      int stock_id;
      std::string new_location;
      std::cout << "Informe o ID do estoque que deseja atualizar a localização:\n";
      std::cin >> stock_id;
      std::cout << "Informe a nova localização: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, new_location);
      bool found = false;
      for (auto &item : stock_items)
      {
        if (item.getStockId() == stock_id)
        {
          item.setStockLocation(new_location);
          std::cout << "Localização atualizada com sucesso!\n";
          found = true;
          break;
        }
      }
      if (!found)
      {
        std::cout << "Item de estoque não encontrado.\n";
      }
    }
    break;
    case 6:
    {
      int stock_id;
      std::string new_date;
      std::cout << "Informe o ID do estoque que deseja atualizar a data da última movimentação:\n";
      std::cin >> stock_id;
      std::cout << "Informe a nova data (YYYY-MM-DD): ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, new_date);
      bool found = false;
      for (auto &item : stock_items)
      {
        if (item.getStockId() == stock_id)
        {
          item.setLastMovementDate(new_date);
          std::cout << "Data da última movimentação atualizada com sucesso!\n";
          found = true;
          break;
        }
      }
      if (!found)
      {
        std::cout << "Item de estoque não encontrado.\n";
      }
    }
    break;
    case 7:
      std::cout << "Retornando ao menu principal...\n";
      break;
    default:
      std::cout << "Opção inválida. Tente novamente.\n";
    }
  }
}