#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> construirSuffixArray(const string& s) {
    int n = s.length();
    vector<int> suffixArray(n);
    vector<pair<string, int>> sufijos;
    for (int i = 0; i < n; i++) {
        sufijos.push_back({s.substr(i), i});
    }
    sort(sufijos.begin(), sufijos.end());
    for (int i = 0; i < n; i++) {
        suffixArray[i] = sufijos[i].second;
    }
    return suffixArray;
}

int main() {
    string entrada;
    cout << "Ingrese una cadena: ";
    getline(cin, entrada);

    vector<int> suffixArray = construirSuffixArray(entrada);

    cout << "Suffix Array y longitudes:" << endl;
    for (int i = 0; i < suffixArray.size(); i++) {
        int indice = suffixArray[i];
        string sufijo = entrada.substr(indice);
        cout << "Sufijo: " << sufijo << " | Longitud: " << sufijo.length() << endl;
    }

    cout << "\nLongitudes de los sufijos ordenados:" << endl;
    for (int i = 0; i < suffixArray.size(); i++) {
        int indice = suffixArray[i];
        int longitud = entrada.length() - indice;
        cout << longitud << endl;
    }

    return 0;
}