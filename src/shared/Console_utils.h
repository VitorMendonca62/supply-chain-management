#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include <iostream>

#ifdef _WIN32
#include <conio.h>
#include <cstdlib>
#else
#include <cstdlib>
#endif

class ConsoleUtils
{
public:
  // Espera o usuário apertar ENTER
  static void wait_for_enter()
  {
#ifdef _WIN32
    _getch();
#else
    std::cin.ignore();
    std::cin.get();
#endif
  }

  // Limpa o console
  static void clear()
  {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
  }

  // Exibe mensagem e aguarda ENTER antes de limpar a tela
  static void pause_and_clear()
  {
    std::cout << "Aperte ENTER para exibir o menu (as mensagens acima serao apagadas)" << std::endl;
    wait_for_enter();
    clear();
  }
};

#endif // CONSOLE_UTILS_H
