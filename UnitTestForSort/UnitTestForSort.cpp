#include "pch.h"
#include "CppUnitTest.h"
#include "..\sort\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForSort
{
	TEST_CLASS(UnitTestForSort)
	{
	public:
		
		TEST_METHOD(TestBinarySearch)
		{
			int size = 13;
			int* array = new int[size] { 0, 1, 2, 3, 4, 4, 4, 4, 8, 9, 10, 10, 10};
			QuickSort(array, 0, size-1);
			Assert::IsTrue(BinarySearch(array, size, 0) == 0);
			Assert::IsTrue(BinarySearch(array, size, 1) == 1);
			Assert::IsTrue(BinarySearch(array, size, 2) == 2);
			Assert::IsTrue(BinarySearch(array, size, 3) == 3);
			Assert::IsTrue(BinarySearch(array, size, 4) == 4 || BinarySearch(array, size, 4) == 5 ||
				BinarySearch(array, size, 4) == 6 || BinarySearch(array, size, 4) == 7);
			Assert::IsTrue(BinarySearch(array, size, 5) == -1);
			Assert::IsTrue(BinarySearch(array, size, 8) == 8);
			Assert::IsTrue(BinarySearch(array, size, 9) == 9);
			Assert::IsTrue(BinarySearch(array, size, 10) == 10
				|| BinarySearch(array, size, 10) == 11 || BinarySearch(array, size, 10) == 12);
			delete[] array;
		}

		TEST_METHOD(TestQuickSort) 
		{
			int size = 10;
			int* array = new int[size] { 3, 1, 0, 4, 4, 2, 2, 0, 3, 3};
			QuickSort(array, 0, size-1);
			Assert::AreEqual(array[0], 0);
			Assert::AreEqual(array[1], 0);
			Assert::AreEqual(array[2], 1);
			Assert::AreEqual(array[3], 2);
			Assert::AreEqual(array[4], 2);
			Assert::AreEqual(array[5], 3);
			Assert::AreEqual(array[6], 3);
			Assert::AreEqual(array[7], 3);
			Assert::AreEqual(array[8], 4);
			Assert::AreEqual(array[9], 4);

			delete[] array;
		}

		TEST_METHOD(TestBubbleSort)
		{
			int size = 10;
			int* array = new int[size] { 3, 1, 0, 4, 4, 2, 2, 0, 3, 3};
			BubbleSort(array, size);
			Assert::AreEqual(array[0], 0);
			Assert::AreEqual(array[1], 0);
			Assert::AreEqual(array[2], 1);
			Assert::AreEqual(array[3], 2);
			Assert::AreEqual(array[4], 2);
			Assert::AreEqual(array[5], 3);
			Assert::AreEqual(array[6], 3);
			Assert::AreEqual(array[7], 3);
			Assert::AreEqual(array[8], 4);
			Assert::AreEqual(array[9], 4);

			delete[] array;
		}

		TEST_METHOD(TestisSorted)
		{
			int size = 10;
			int* array = new int[size];
			for (int i = 0; i < size; i++)
			{
				array[i] = 10 - i;
			}
			Assert::IsFalse(isSorted(array, size));
			BogoSort(array, size);
			Assert::IsTrue(isSorted(array, size));
			delete[] array;
		}

		TEST_METHOD(TestBogoSort)
		{
			int size = 5;
			int* array = new int[size] {1, 3, 2, 0, 4};
			BogoSort(array, size);
			Assert::AreEqual(array[0], 0);
			Assert::AreEqual(array[1], 1);
			Assert::AreEqual(array[2], 2);
			Assert::AreEqual(array[3], 3);
			Assert::AreEqual(array[4], 4);
			delete[] array;
		}

		TEST_METHOD(TestCountingSort)
		{
			int size = 4;
			char* array = new char[size];
			array[0] = 'c';
			array[1] = 'd';
			array[2] = 'a';
			array[3] = 'b';
			Assert::IsTrue(array[0] == 'c');
			Assert::IsTrue(array[1] == 'd');
			Assert::IsTrue(array[2] == 'a');
			Assert::IsTrue(array[3] == 'b');

			CountingSort(array, size);

			Assert::IsTrue(array[0] == 'a');
			Assert::IsTrue(array[1] == 'b');
			Assert::IsTrue(array[2] == 'c');
			Assert::IsTrue(array[3] == 'd');

			delete[] array;
		}
	};
}
