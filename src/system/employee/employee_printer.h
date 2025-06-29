#ifndef EMPLOYEE_PRINTER_H
#define EMPLOYEE_PRINTER_H

#include <User_Printer.h>

class EmployeePrinter : public UserPrinter
{
public:
  EmployeePrinter() {};
  void init();
  void print_menu();
};

#endif