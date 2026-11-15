#include <cstdint>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Dijkstra
{
private:
    static constexpr int MAX_V = INT32_MAX / 2;


    static bool dijkstramtd(const vector<vector<pair<int, int>>>& ady, const int nt, const int inic, const int fin, vector<int>& ruta, int& costo);
public:
    Dijkstra(wstring arch);
};

