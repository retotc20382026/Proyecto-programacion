
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


namespace fs = std::filesystem;

class LecturaArchivo
{
private:
	
	static bool leerarchivo(const fs::path& ruta, std::string& cad);
	static wstring stringawstring(const string& s);
public:

	static fs::path base;
	static fs::path directorioBase(const char* argv0);
	static vector<wstring> leerTrie(const wstring& arch);
	static bool leerDijkstra(const wstring& arch, int& vertices, int& aristas,vector<vector<pair<int, int>>>& ady);
};

