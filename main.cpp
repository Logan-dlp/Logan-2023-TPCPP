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

void TriParInsertion(int* tab, int size){
    for (int i = 1; i < size; ++i) {
        int aux = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > aux){
            tab[j + 1] = tab[j];
            j -= 1;
        }
        tab[j + 1] = aux;
    }
}

int main(){
    int tab[] = {5, 2, 7, 4, 9};
    int size = 5;

    TriParInsertion(tab, size);
    DisplayArray(tab, size);
    
    return 0;
}