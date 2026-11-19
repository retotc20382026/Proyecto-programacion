#include "Menu.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "Trie.h"
#include "Dijkstra.h"

#define FIN_COLOR   "\033[0m"
#define ROJO         "\x1b[38;2;255;0;0m"
#define NARANJA       "\x1b[38;2;255;127;0m"
#define AMARILLO      "\x1b[38;2;255;255;0m"
#define AMVER   "\x1b[38;2;127;255;0m"
#define VERDE       "\x1b[38;2;0;255;0m"
#define MENTA "\x1b[38;2;0;255;127m"
#define CYAN        "\x1b[38;2;0;255;255m"
#define AGUA        "\x1b[38;2;0;127;255m"
#define AZUL        "\x1b[38;2;0;0;255m"
#define VIOLETA       "\x1b[38;2;127;0;255m"
#define MAGENTA     "\x1b[38;2;255;0;255m"
#define ROSA         "\x1b[38;2;255;0;127m"

#define ROJO_CLARO          "\x1b[38;2;255;127;127m"
#define NARANJA_CLARO       "\x1b[38;2;255;191;127m"
#define AMARILLO_CLARO       "\x1b[38;2;255;255;127m"
#define AMVER_CLARO   "\x1b[38;2;191;255;127m"
#define VERDE_CLARO        "\x1b[38;2;127;255;127m"
#define MENTA_CLARO "\x1b[38;2;127;255;191m"
#define CYAN_CLARO         "\x1b[38;2;127;255;255m"
#define AGUA_CLARO        "\x1b[38;2;127;191;255m"
#define AZUL_CLARO         "\x1b[38;2;127;127;255m"
#define VIOLETA_CLARO       "\x1b[38;2;191;127;255m"
#define MAGENTA_CLARO      "\x1b[38;2;255;127;255m"
#define ROSA_CLARO         "\x1b[38;2;255;127;191m"

#define BLANCO   "\x1b[38;2;255;255;255m"


using namespace std;

void Menu::limpiar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Menu::esperarenter() {
    cout << BLANCO "Presiona ENTER para continuar...\n"<<FIN_COLOR;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Menu::imprimirportada() {
    cout << AGUA << "            _                     ___  __    \n"
        " /\\ /\\ _ __| |__   __ _ _ __     /___\\/ _\\   \n"
        "/ / \\ \\ '__| '_ \\ / _` | '_ \\   //  //\\ \\    \n"
        "\\ \\_/ / |  | |_) | (_| | | | | / \\_// _\\ \\   \n"
        " \\___/|_|  |_.__/ \\__,_|_| |_| \\___/  \\__/   \n" << FIN_COLOR;
    cout << AGUA_CLARO << "                                \n"
        "                %               \n"
        "               +%-              \n"
        "               = %              \n"
        "                 %              \n"
        "             % %=* :            \n"
        "             +.*=%+%%           \n"
        "            =***#%#%%%          \n"
        "            :%%%%%=%%%          \n"
        "            .%%%%%+*%%          \n"
        "            % %%%%=%%%          \n"
        "            * %%%%%%%%          \n"
        "            %  %%%:%%%          \n"
        "           :  %%+%%#%%          \n"
        "     -=*=%%%+ =# %%%%%#%#       \n"
        "%%# #%%%%%%%%%%%%%%%%%%%%%%%%   \n"
        "%%%#%%%%%%%%%%%%%%%%%#%%%%%%%%: \n"
        "%#%%%%%#%%%%%%%%%%%%%%%%%%%%%.  \n"
        "%%%%%%-%%    %%*:...   #.....#%%\n"
        "%%%%%%%%%%%%%%%%= %%%%%%%%*%%%%%\n\n"
        "" << FIN_COLOR;
}

fs::path Menu::directorioBase(const char* argv0) {
    std::error_code ec;
    fs::path exe = fs::absolute(argv0 ? argv0 : "", ec);
    if (ec || exe.empty()) return fs::current_path(ec);
    return exe.parent_path();
}


bool Menu::leerarchivo(const fs::path& ruta, std::string& cad) {
    std::ifstream archivo(ruta, std::ios::binary);
    if (!archivo.is_open()) return false;

    std::ostringstream ss;
    ss << archivo.rdbuf();
    cad = ss.str();
    return true;
}

int Menu::Correr(int argc, char* argv[]) {
    /*
    fs::path base = directorioBase(argc > 0 ? argv[0] : nullptr);
    std::string archivotxt;
    if (leerarchivo(base / "archivo.txt", archivotxt)) {
        return 0;
    }
    else {
        return -666;
    }
    */
    char respuesta = 0;
    bool continuar = true;
    while (continuar) {
        limpiar();
        imprimirportada();
        cout << BLANCO <<"1.- |       Trie        |\n"
        "2.- |     Dijkstra      |\n"
        "3.- |      Kruskal      |\n"
        "4.- |      Mochila      |\n"<< FIN_COLOR;
        cout << ROJO<<"0.- |       Salir       | -->\n\n"<< FIN_COLOR;
        cin >> respuesta;
        respuesta -= 48;
        switch (respuesta) {
        case 1: {
            Trie* tr = new Trie(L"trie.txt");
            delete tr;
            esperarenter();
            break;
        }
        case 2: {
              Dijkstra* dj = new Dijkstra(L"dijkstra.txt");
              delete dj;
              esperarenter();
              break;
        }
        case 3: {
            cout << "Seleccionado 3\n";
            esperarenter();
            break;
        }
        case 4: {
            cout << "Seleccionado 4\n";
            esperarenter();
            break;
        }
        case 0:
            cout << "Salida\n";
            continuar = false;
            break;
        }
        
        cout << "\n";
    }
    return 0;
}