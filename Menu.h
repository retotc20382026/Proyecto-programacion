#pragma once

#include <filesystem>

namespace fs = std::filesystem;

class Menu
{
public:
	static void limpiar();
	static void esperarenter();
	static void imprimirportada();
	static fs::path directorioBase(const char* argv0);
	static bool leerarchivo(const fs::path& ruta, std::string& cad);
	static int Correr(int argc, char* argv[]);
};

