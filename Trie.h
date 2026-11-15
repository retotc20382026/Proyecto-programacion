#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Trie
{
private:
    static const wstring CARACTERES;
    vector<wstring> clls;
    struct TrieNodo {
        TrieNodo* hjs[64];
        TrieNodo() {
            for (int i = 0; i < CARACTERES.size(); i++) {
                hjs[i] = nullptr;
            }
        }
        ~TrieNodo() {
            for (int i = 0; i < CARACTERES.size(); i++) {
                delete hjs[i];
            }
        }
        bool final = false;
        wstring nombre;
    };
	TrieNodo* raiz;

    static wchar_t volvermayusculas(wchar_t c);

    static int carAindic(wchar_t c);

    static wchar_t indicAcar(int i);

    static void insertar(TrieNodo* raiz, const wstring& calle);

    static void recolectar(TrieNodo* nodo, const wstring& prefijo, vector<wstring>& res);
    static vector<wstring> autocompletar(TrieNodo* raiz, const wstring& prefijo);

public:
    Trie(wstring arch);
};

