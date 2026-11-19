#include "Trie.h"

#include <locale>
#include <algorithm>
#include <cwctype>
#include <clocale>
#include <unordered_map>

#include "LecturaArchivo.h"


const wstring Trie::CARACTERES = L"ABCDEFGHIJKLMNÑOPQRSTUVWXYZabcdefghijklmnñopqrstuvwxyzÁÉÍÓÚáéíóú";


int Trie::carAindic(wchar_t c) {
    for (int i = 0; i < CARACTERES.size(); i++) {
        if (c == CARACTERES[i]) {
            return i;
        }
    }
    return -1;
}

wchar_t Trie::indicAcar(int i) {
    return (i >= 0 && i < CARACTERES.size()) ? CARACTERES[i] : -1;
}

void Trie::insertar(TrieNodo* raiz, const wstring& calle) {
    TrieNodo* nodo = raiz;
    for (wchar_t c : calle) {
        int indic = carAindic(c);
        if (indic >= 0 && indic < CARACTERES.size()) {
            if (!nodo->hjs[indic]) {
                nodo->hjs[indic] = new TrieNodo();
            }
            nodo = nodo->hjs[indic];
        }
        else {
            return;
        }
    }
    nodo->final = true;
    nodo->nombre = calle;
}

void Trie::recolectar(TrieNodo* nodo, const wstring& prefijo, vector<wstring>& res) {
    if (nodo->final) {
        res.push_back(prefijo);
    }
    for (int i = 0; i < CARACTERES.size(); i++) {
        if (nodo->hjs[i])
            recolectar(nodo->hjs[i], prefijo + indicAcar(i), res);
    }
}

vector<wstring> Trie::autocompletar(TrieNodo* raiz, const wstring& prefijo) {
    TrieNodo* nodo = raiz;
    for (wchar_t c : prefijo) {
        int indic = carAindic(c);
        if (indic >= 0 && nodo->hjs[indic]) {
            nodo = nodo->hjs[indic];
        }
        else {
            return {};
        }

    }
    vector<wstring> res;
    recolectar(nodo, prefijo, res);
    return res;
}


Trie::Trie(wstring arch) {
    this->clls = LecturaArchivo::leerTrie(arch);
    TrieNodo* raiz = new TrieNodo();
    for (const auto& c : this->clls) {
        insertar(raiz, c);
    }
    wstring prefijo;
    wcin >> prefijo;
    vector<wstring> top = autocompletar(raiz, prefijo);
    if (top.empty()) {
        cout << "No hay resultados" << endl;
    }
    else {
        for (const auto& calle : top) {
            wcout << calle << endl;
        }
    }
    delete raiz;
}