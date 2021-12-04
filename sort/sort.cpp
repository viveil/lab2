#include <iostream>
#include "Header.h"

void generateArray(int* array, size_t size) {
	for (int i = 0; i < size; i++)
		array[i] = rand();
}


int main() {

	std::cout << "Time Difficulty Comparison for QuickSort and BubbleSort" << std::endl;
	std::cout << "Quick Sort" << std::endl;;
	for (int size = 10; size <= 100000; size *= 10) {
		int* quick_array = new int[size];
		generateArray(quick_array, size);
		double timer = 0;
		for (int i = 0; i < 10; i++) {
			clock_t begin = clock();
			QuickSort(quick_array, 0, size-1);
			clock_t end = clock();
			timer += end - begin;
		}
		std::cout << "For " << size << " elements: " << timer / 10 / CLOCKS_PER_SEC << " seconds" << std::endl;
		delete[] quick_array;
	}

	std::cout << "Bubble Sort" << std::endl;
	for (int size = 10; size <= 100000; size *= 10) {
		int* bubble_array = new int[size];
		generateArray(bubble_array, size);
		double timer = 0;
		for (int i = 0; i < 10; i++) {
			clock_t begin = clock();
			BubbleSort(bubble_array, size);
			clock_t end = clock();
			timer += end - begin;
		}
		std::cout << "For "<< size << " elements: " << timer / 10 / CLOCKS_PER_SEC << " seconds" << std::endl;
		delete[] bubble_array;
	}

	
}
