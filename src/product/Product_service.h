#ifndef PRODUCT_SERVICE_H
#define PRODUCT_SERVICE_H

#include "../shared/Service.h"
#include <iostream>

class ProductService : public Service
{
public:
  ProductService() = default;

  void create() override;
  void getAll() override;
  void getOne() override;
  void update() override;
  void deleteItem() override;

  ~ProductService() override = default;
};

#endif