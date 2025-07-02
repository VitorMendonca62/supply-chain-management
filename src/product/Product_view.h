#ifndef PRODUCT_VIEW_H
#define PRODUCT_VIEW_H

#include "../shared/Menu_view.h"

class ProductView : public MenuView
{
public:
  ProductView() {};
  void print_menu() const override;
  void call_menu_function(int action) const override;

};

#endif