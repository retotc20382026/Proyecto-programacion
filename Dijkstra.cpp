#include "Dijkstra.h"







bool Dijkstra::dijkstramtd(const vector<vector<pair<int, int>>>& ady, const int nt, const int inic, const int fin, vector<int>& ruta, int& costo) {
    ruta.clear();
    int* dist = new int[nt];
    bool* usado = new bool[nt];
    int* prede = new int[nt];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < nt; i++) {
        usado[i] = false;
        dist[i] = MAX_V;
        prede[i] = -1;
    }
    dist[inic] = 0;
    pq.push({ 0, inic });

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (!usado[u]) {
            usado[u] = true;
            if (u != fin) {
                for (auto [v, w] : ady[u]) {
                    if (d + w < dist[v]) {
                        dist[v] = d + w;
                        prede[v] = u;
                        pq.push({ dist[v], v });
                    }
                }
            }
            else {
                break;
            }

        }

    }
    if (dist[fin] < MAX_V) {
        for (int v = fin; v != -1; v = prede[v]) {
            ruta.push_back(v);
        }
        reverse(ruta.begin(), ruta.end());
        costo = dist[fin];
        delete[] dist;
        delete[] usado;
        delete[] prede;
        return true;
    }
    else {
        delete[] dist;
        delete[] usado;
        delete[] prede;
        return false;
    }

}

Dijkstra::Dijkstra(wstring arch) {
    int vertices, aristas, inic, fin;
    cin >> vertices;
    cin >> aristas;
    vector<vector<pair<int, int>>> ady(vertices);
    for (int i = 0; i < aristas; i++) {
        int orig, dest, peso;
        cin >> orig >> dest >> peso;
        ady[orig].push_back({ dest, peso });
        ady[dest].push_back({ orig, peso });
    }
    cin >> inic;
    cin >> fin;
    vector<int> ruta;
    int costo = 0;
    if (dijkstramtd(ady, vertices, inic, fin, ruta, costo)) {
        cout << "Ruta: ";
        for (size_t i = 0; i < ruta.size(); i++) {
            cout << ruta[i];
            if (i + 1 < ruta.size()) cout << " -> ";
        }
        cout << "\nCosto total: " << costo << "\n";
    }
    else {
        cout << "No hay ruta";
    }
}