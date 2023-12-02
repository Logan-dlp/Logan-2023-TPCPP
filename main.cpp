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

void Swap(int* tab, int left, int right){
    int tabLeft = tab[left];
    tab[left] = tab[right];
    tab[right] = tabLeft;
}

int Partition(int* tab, int low, int high){
    int pivot_index = high;
    int l = low;

    for (int i = low; i < high; ++i) {
        if (tab[i] <= tab[pivot_index]){
            Swap(tab, i, l);
            l++;
        }
    }
    Swap(tab, l, pivot_index);

    return l;
}

void QuickShort(int* tab, int size, int low = 0, int high = 0){

    if (high == 0){
        high = size - 1;
    }

    if (low < high){
        int p = Partition(tab, low, high);

        QuickShort(tab, p, low, p - 1);
        QuickShort(tab, high + 1, p + 1, high);
    }
}

int main(){
    int tab[] = {5, 2, 7, 4, 9};
    int size = 5;

    QuickShort(tab, size);
    DisplayArray(tab, size);
    
    return 0;
}