
#pragma once

#include "myList.h"
#include <algorithm>
#include <cstring>
#include <vector>
#include <cctype>

template<typename T, size_t N>
void mySort(T(&array)[N]) {
    std::sort(std::begin(array), std::end(array));
}
template<int size1, int size2>
void mySort(char (&array)[size1][size2]) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size1 - 1; j++) {
            char str1[size2], str2[size2];
            strcpy(str1, array[j]);
            strcpy(str2, array[j + 1]);
            for (int k = 0; str1[k] != '\0'; k++) {
                str1[k] = toupper(str1[k]);
            }
            for (int k = 0; str2[k] != '\0'; k++) {
                str2[k] = toupper(str2[k]);
            }
            if (strcmp(str1, str2) > 0) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

template<typename Container>
void mySort(Container& container) {
    std::sort(container.begin(), container.end());
}


template<typename T>
void mySort(MyList<T>& list) {
    list.sort();
}

