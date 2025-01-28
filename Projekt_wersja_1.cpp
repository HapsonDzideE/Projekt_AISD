#include <iostream>
#include <vector>
#include <fstream>

// Funkcja do sprawdzania, czy dany punkt w tablicy tworzy prawidłowy "plus"
bool czyPoprawnyPlus(const std::vector<std::vector<int>>& macierz, int w, int k) {
    // Sprawdzenie czy centrum "plusa" jest jedynka
    if (macierz[w][k] != 1) return false;
    // Sprawdzanie czy ramiona "plusa" są jedynkami
    if (macierz[w - 1][k] != 1 || macierz[w + 1][k] != 1 ||
        macierz[w][k - 1] != 1 || macierz[w][k + 1] != 1) {
        return false;
    }
    
    // Sprawdzanie czy wokól "plusa" sa zera (lub granice tablicy)
    if ((w - 2 >= 0 && macierz[w - 2][k] != 0) ||
        (w + 2 < macierz.size() && macierz[w + 2][k] != 0) ||
        (k - 2 >= 0 && macierz[w][k - 2] != 0) ||
        (k + 2 < macierz[0].size() && macierz[w][k + 2] != 0) ||
        (w - 1 >= 0 && k - 1 >= 0 && macierz[w - 1][k - 1] != 0) ||
        (w - 1 >= 0 && k + 1 < macierz[0].size() && macierz[w - 1][k + 1] != 0) ||
        (w + 1 < macierz.size() && k - 1 >= 0 && macierz[w + 1][k - 1] != 0) ||
        (w + 1 < macierz.size() && k + 1 < macierz[0].size() && macierz[w + 1][k + 1] != 0)) {
        return false;
    }

    return true;
}

// Funkcja do liczenia liczby prawidlowych "plusów" w tablicy
int liczbaPoprawnychPlusow(const std::vector<std::vector<int>>& macierz) {
    int w = macierz.size();
    int k = macierz[0].size();
    int licznik = 0;

    // Przechodzi przez wnetrze tablicy (pomija krawedzie)
    for (int i = 1; i < w - 1; ++i) {
        for (int j = 1; j < k - 1; ++j) {
            if (czyPoprawnyPlus(macierz, i, j)) {
                ++licznik;
            }
        }
    }

    return licznik;
}


int main(){

    return 0;
}
