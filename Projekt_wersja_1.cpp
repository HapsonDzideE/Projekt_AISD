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
}

int main(){

    return 0;
}
