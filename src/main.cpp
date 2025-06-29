#include <iostream>
#include <string>
#include <vector>
#include "system/system.h"
#include "shared/menu_view.h"

int main() { // Adicione parênteses aqui
    System system;
    MenuView* menu_view = system.print_start();
    system.print_menu(*menu_view);
    return 0;
}