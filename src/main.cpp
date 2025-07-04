#include <iostream>
#include <string>
#include <vector>
#include "system/System.h"
#include "shared/Menu_view.h"

int main() { // Adicione parenteses aqui
    System system;
    MenuView* menu_view = system.print_start();
    system.print_menu(*menu_view);
    return 0;
}