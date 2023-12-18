#include <iostream>
#include <chrono>
#include <random>

void DisplayArray(int* tab, int size){
    for (int i = 0; i < size; ++i) {
        std::cout << tab[i] << ".";
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

void RandomArray(int* tab, int size){

    constexpr int MIN = 0;
    constexpr int MAX = 9;

    for (int i = 0; i < size; ++i) {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(MIN, MAX);

        tab[i] = distr(eng);
    }
}

int main(){
    // 1.

    int tab1[] = {7, 1, 5, 2, 3};
    int size1 = std::size(tab1);

    auto start = std::chrono::high_resolution_clock::now();

    QuickShort(tab1, size1);
    //DisplayArray(tab1, size1);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Execution Time : " << duration.count() << " microseconds." << std::endl;

    // 2.


    int tab2[100];
    int size2 = std::size(tab2);

    RandomArray(tab2, size2);

    start = std::chrono::high_resolution_clock::now();

    QuickShort(tab2, size2);
    //DisplayArray(tab2, size2);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Execution Time : " << duration.count() << " microseconds." << std::endl;

    // 3.

    int tab3[1000];
    int size3 = std::size(tab3);

    start = std::chrono::high_resolution_clock::now();

    RandomArray(tab3, size3);

    QuickShort(tab3, size3);
    //DisplayArray(tab3, size3);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Execution Time : " << duration.count() << " microseconds." << std::endl;

    // 4.

    int tab4[1000];
    int size4 = std::size(tab4);

    RandomArray(tab4, size4);

    start = std::chrono::high_resolution_clock::now();

    InverseTriABulle(tab4, size4);
    //DisplayArray(tab4, size4);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Execution Time : " << duration.count() << " microseconds." << std::endl;


    return 0;
}