#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <User_Printer.h>

class ManagerPrinter : public UserPrinter
{
public:
  ManagerPrinter() {};
  void init();
  void print_menu();
};

#endif