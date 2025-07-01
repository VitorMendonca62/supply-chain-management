#ifndef VENDOR_VIEW_H
#define VENDOR_VIEW_H

#include "../shared/menu_view.h"

class VendorView : public MenuView
{
public:
  VendorView() {};
  void print_menu() const override;
  void call_menu_function() const override;

};

#endif