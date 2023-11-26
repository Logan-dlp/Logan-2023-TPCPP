#include <iostream>

void DisplayArray(int* tab, int size){
    for (int i = 0; i < size; ++i) {
        std::cout << tab[i];
    }
    std::cout << std::endl;
}

void TriABulle(int* tab, int size){
    for (int i = size - 1; i > 0 ; i--) {
        for (int j = 0; j < i - 1; ++j) {
            if (tab[j] > tab[j+1]){
                int aux = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = aux;
            }
        }
    }
}

void InverseTriABulle(int* tab, int size){
    for (int i = 0; i < size ; i++) {
        for (int j = size; j > i; j--) {
            if (tab[j] > tab[j-1]){
                int aux = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = aux;
            }
        }
    }
}

int main(){
    int tab[] = {5, 2, 7, 4, 9};
    int size = 5;
    DisplayArray(tab, size); // mélanger
    TriABulle(tab, size);
    DisplayArray(tab, size); // croissant
    InverseTriABulle(tab, size);
    DisplayArray(tab, size); // décroissant
    
    return 0;
}