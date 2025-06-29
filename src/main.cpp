#include <iostream>
#include <string>
#include <vector>
#include "system/system.h"
#include "system/user_view.h"

int main() { // Adicione parênteses aqui
    System system;
    UserView* user_view = system.print_start();
    system.print_menu(*user_view);
    return 0;
}