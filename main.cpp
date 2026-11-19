#include "Menu.h"

#include <locale>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif


#include "LecturaArchivo.h"

int main(int argc, char* argv[]){
    std::locale::global(std::locale(""));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());
#ifdef _WIN32
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
#endif
    LecturaArchivo::base = LecturaArchivo::directorioBase(argc > 0 ? argv[0] : nullptr);
    return Menu::Correr(argc, argv);
}
