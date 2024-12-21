//
// Created by Ja_Vani on 5.12.2024.
//

#ifndef MY_SORT_H
#define MY_SORT_H
#include <algorithm>

// template<typename T>
// bool comp(const T &a, const T &b);
template<typename T>
void swap(T* a, T* b) {
    T temp = std::move(*a);
    *a =  std::move(*b);
    *b = std::move(temp);
}

template<typename T, typename Compare>
void insert_sort(T *first, T *last, Compare comp) {
    T *j;
    for (T *i = first; i != last; ++i) {
        j = i;

        while (j!=first && !comp(*(j-1), *(j))) {
            swap((j-1), (j));
            j--;
        }
    }
}

template<typename T, typename Compare>
T *partition(T *first, T *last, Compare comp) {
    int pivot;
    int* i = first - 1;  // Указатель для меньших элементов
    int count = 0;
    for (int* j = first; j < last; ++j) {
        count++;
    }
    int *m = i + (count / 2);
    if(*first > *(last-1)) {
        if(*m > *first) {
            pivot = *first;
            swap(first, (last-1));
        } else if(*m > *(last-1)) {
            pivot = *m;
            swap(m, (last-1));
        } else {
            pivot = *(last-1);
        }
    } else {
        if(*m > *(last-1)) {
            pivot = *(last-1);
        } else if(*m > *(first)) {
            pivot = *m;
            swap(m, (last-1));
        } else {
            pivot = *first;
            swap(first, (last-1));
        }
    }

    for (int* j = first; j < last; ++j) {
        if (comp(*j, pivot)) {
            ++i;
            swap(i, j); // Меняем местами элементы
        }
    }
    swap(i + 1, last - 1); // Устанавливаем pivot на правильное место
    return (i + 1);    // Возвращаем указатель на опорный элемент
}

template<typename T, typename Compare>
void quick_sort(T *first, T *last, Compare comp) {
    while (first < last) {
        if(last - first <= 20) {
            insert_sort(first, last, comp);
            break;
        }
        T* pi = partition(first, last, comp); // Получаем указатель на опорный элемент
        if(pi - first < last - pi + 1){
            quick_sort(first, pi, comp);         // Сортируем левую часть массива
            first = pi + 1;
        } else {
            quick_sort(pi + 1, last, comp);         // Сортируем левую часть массива
            last = pi;
        }
    }
}


#endif //MY_SORT_H
