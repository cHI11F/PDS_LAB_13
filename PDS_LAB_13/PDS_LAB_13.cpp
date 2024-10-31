#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <Windows.h>

using namespace std;

void readGraph(const string& filename, vector<vector<int>>& adjList, int& n) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }

    infile >> n;
    adjList.assign(n, vector<int>());

    int u, v;
    while (infile >> u >> v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    infile.close();
}

vector<int> greedyColoring(const vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> colors(n, -1);

    colors[0] = 0;

    for (int u = 1; u < n; u++) {

        vector<bool> available(n, true);
        for (int v : adjList[u]) {
            if (colors[v] != -1) {
                available[colors[v]] = false;
            }
        }

        int cr;
        for (cr = 0; cr < n; cr++) {
            if (available[cr]) {
                break;
            }
        }

        colors[u] = cr;
    }

    return colors;
}

void printColoring(const vector<int>& colors) {
    int maxColor = *max_element(colors.begin(), colors.end());
    cout << "Мінімальна кількість кольорів: " << maxColor + 1 << endl;
    cout << "Призначення кольорів для вершин:" << endl;
    for (int i = 0; i < colors.size(); i++) {
        cout << "Вершина " << i << ": Колір " << colors[i] << endl;
    }
}

int main() {
  
    string inputFile = "123.txt";
    vector<vector<int>> adjList;
    int n;

    readGraph(inputFile, adjList, n);

    vector<int> colors = greedyColoring(adjList);
    printColoring(colors);

    return 0;
}
