#ifndef VENDOR_VIEW_H
#define VENDOR_VIEW_H

#include "../shared/Menu_view.h"
#include <vector>
#include "vendor.h"
class VendorView : public MenuView
{
private:
  std::vector<Vendor> vendors;
public:
  VendorView() {};
  void print_menu() const override;
  void call_menu_function(int action) const override;
  void pushVendor( Vendor );
  void createVendor( ); 
  Vendor getVendor( ) const;

  
};

#endif