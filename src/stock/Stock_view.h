#ifndef STOCK_VIEW_H
#define STOCK_VIEW_H

#include "../shared/menu_view.h"

class StockView : public MenuView
{
public:
  StockView() {};
  void print_menu() const override;
  void call_menu_function() const override;

};

#endif