/******************************************************************************
 * Arquivo     : Stock_service.h
 * Autor       : Vitor Mendonça
 * Criado em   : 04/07/2025
 * Descriçao   :
 *   Implementa a interface Service para operações de estoque.
 *
 * Projeto     : Projeto prático de EDOO
 ******************************************************************************/

#ifndef STOCK_SERVICE_H
#define STOCK_SERVICE_H

#include "../shared/Service.h"

class StockService : public Service
{
public:
  StockService() = default;

  void create() override;
  void getAll() override;
  void getOne() override;
  void update() override;
  void deleteItem() override;
  
  void updateStockItemQuantity();
  void updateStockItemLocation();
  void updateStockItemLastMovementDate();
  

  ~StockService() override = default;
};

#endif