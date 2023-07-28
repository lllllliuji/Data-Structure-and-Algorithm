#pragma once

#include <iostream>

void quick_sort(int arr[], int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = arr[l + r >> 1];
    while (i < j) {
        do i++;
        while (arr[i] < x);
        do j--;
        while (arr[j] > x);
        if (i < j) std::swap(arr[i], arr[j]);
    }
    quick_sort(arr, l, j), quick_sort(arr, j + 1, r);
}