#include "LecturaArchivo.h"


#include <cstdint>



fs::path LecturaArchivo::base;

fs::path LecturaArchivo::directorioBase(const char* argv0) {
    std::error_code ec;
    fs::path exe = fs::absolute(argv0 ? argv0 : "", ec);
    if (ec || exe.empty()) return fs::current_path(ec);
    return exe.parent_path();
}

wstring LecturaArchivo::stringawstring(const string& s) {
    wstring result;
    result.reserve(s.size());
    for (size_t i = 0; i < s.size(); ) {
        unsigned char c = s[i];
        uint32_t cp;
        if (c < 0x80) { cp = c; i += 1; }
        else if (c < 0xE0) { cp = ((c & 0x1F) << 6) | (s[i + 1] & 0x3F); i += 2; }
        else if (c < 0xF0) { cp = ((c & 0x0F) << 12) | ((s[i + 1] & 0x3F) << 6) | (s[i + 2] & 0x3F); i += 3; }
        else { cp = ((c & 0x07) << 18) | ((s[i + 1] & 0x3F) << 12) | ((s[i + 2] & 0x3F) << 6) | (s[i + 3] & 0x3F); i += 4; }
        result.push_back(static_cast<wchar_t>(cp));
    }
    return result;
}


bool LecturaArchivo::leerarchivo(const fs::path& ruta, std::string& cad) {
    std::ifstream archivo(ruta, std::ios::binary);
    if (!archivo.is_open()) return false;

    std::ostringstream ss;
    ss << archivo.rdbuf();
    cad = ss.str();
    return true;
}


vector<wstring> LecturaArchivo::leerTrie(const wstring& arch) {
    std::string contenido;
    vector<wstring> lista;
    if (leerarchivo(base / arch, contenido)) {
        istringstream in(contenido);
        string token;
        while (in >> token) {
            lista.push_back(stringawstring(token));
        }
    }
    return lista;
}

bool LecturaArchivo::leerDijkstra(const wstring& arch, int& vertices, int& aristas,
    vector<vector<pair<int, int>>>& ady) {
    std::string contenido;
    if (leerarchivo(base / arch, contenido)) {
        istringstream in(contenido);
        in >> vertices >> aristas;
        ady.assign(vertices, {});
        for (int i = 0; i < aristas; i++) {
            int orig, dest, peso;
            in >> orig >> dest >> peso;
            ady[orig].push_back({ dest, peso });
            ady[dest].push_back({ orig, peso });
        }
        return true;
    }
    return false;
}