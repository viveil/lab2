#pragma once
#include <iostream>
#include <ctime>
#include <cstddef>


using namespace std;

int BinarySearch(int* array, int size, int FoundItem) {
    int right = size - 1;
    int left = 0;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (array[middle] == FoundItem) return  middle;
        else if (array[middle] > FoundItem) right = middle - 1;
        else if (array[middle] < FoundItem) left = middle + 1;
    }
    return -1;
}

void QuickSort(int* array, int low, int high) {
    int left = low;
    int right = high;
    int middle = array[(left + right) / 2];
    while (left <= right)
    {
        while (array[left] < middle) left++;
        while (array[right] > middle) right--;
        if (left <= right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
    if (low < right) QuickSort(array, low, right); // sort the sub-array
    if (left < high) QuickSort(array, left, high);
}

void BubbleSort(int* array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
//checking whether the array is sorted (for bogosort)
bool isSorted(int* array, int size) {
    while (size > 1) {
        if (array[size - 1] < array[size - 2]) return false;
        size--;
    }
    return true;
}


void BogoSort(int* array, int size) {
    while (!isSorted(array, size)) {
        for (int i = 0; i < size; ++i)
            swap(array[i], array[(rand() % size)]);
    }
}

void CountingSort(char* array, int size) {
    int max = 0;
    int temp;

    for (int i = 0; i < size; i++)
        if (array[i] > max) max = array[i];
    max++;
    int* counting_array = new int[max];
    for (int i = 0; i < max; i++)
    {
        counting_array[i] = 0;
    }


    for (int i = 0; i < size; i++)
    {
        temp = array[i];
        counting_array[temp]++;
    }

    int pos = 0;

    for (int j = 0; j < max; j++) {
        while (counting_array[j] != 0) {
            array[pos] = j;
            counting_array[j]--;
            pos++;
        }
    }

    delete counting_array;
}

