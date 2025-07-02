#ifndef EMPLOYEE_VIEW_H
#define EMPLOYEE_VIEW_H

#include "../shared/Menu_view.h"

class EmployeeView : public MenuView
{
public:
  EmployeeView() {};
  void print_menu() const override;
  void call_menu_function(int action) const override;

};

#endif