#include <iostream>

int tab[] = {5, 2, 7, 4, 9};

void DisplayTriABulle(){
    for (int i = 0; i < std::size(tab); ++i) {
        std::cout << tab[i] << std::endl;
    }
}

void TriABulle(){
    for (int i = std::size(tab) - 1; i > 0 ; i--) {
        for (int j = 0; j < i - 1; ++j) {
            if (tab[j] > tab[j+1]){
                int aux = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = aux;
            }
        }
    }
}

void InverseTriABulle(){
    for (int i = 0; i < std::size(tab) ; i++) {
        for (int j = std::size(tab); j > i - 1; j--) {
            if (tab[j] > tab[j-1]){
                int aux = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = aux;
            }
        }
    }
}

int main(){
    TriABulle();
    DisplayTriABulle();
    InverseTriABulle();
    DisplayTriABulle();
    return 0;
}