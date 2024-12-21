#include <chrono>
#include <fstream>
#include <iostream>
#include "my_sort.h"

const int mass_size = 1000;

int main() {
    int arr[mass_size];
    std::chrono::duration<long long, std::ratio<1, 1000000000>> quick_sort_elapsed[mass_size], insert_sort_elapsed[mass_size];
    for(int i = 1; i <= mass_size ; i++) {
        for(int t = 0; t < i; t++) {
            arr[t] = mass_size-t;
        }
        auto start_time = std::chrono::steady_clock::now();
        quick_sort(arr, arr + i,  [](int a, int b) { return a < b; });
        auto end_time = std::chrono::steady_clock::now();
        quick_sort_elapsed[i-1] = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        // for(int t = 0; t < i; t++) {
        //     arr[t] = mass_size-t;
        // }
        // start_time = std::chrono::steady_clock::now();
        // insert_sort(arr, arr + i,  [](int a, int b) { return a < b; });
        // end_time = std::chrono::steady_clock::now();
        // insert_sort_elapsed[i-1] = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    }
    std::ofstream q_out("q_out.txt");
    std::ofstream i_out("i_out.txt");
    for(int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for(auto i : quick_sort_elapsed) {
        q_out << i << std::endl;
    }
    for(auto i : insert_sort_elapsed) {
        i_out << i << std::endl;
    }
    return 0;
}
