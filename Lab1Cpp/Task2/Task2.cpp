#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;
/*Елисеев Вадим, ИВТ-5, Вариант 7
Преобразование: 2D → 1D. Двумерный массив 5х5 целых чисел необходимо выложить в один ряд по элементам слева направо и сверху вниз, исключая все элементы на нечетных строках. Инициализация: заполнить массив факториалами: x[i][j] = i! + j!. Вывод на экран: на каждый элемент массива отвести 8 позиций.*/
int factorial(int num) {
	int fact = 1;
	for (int i = 1; i <= num; i++) {
		fact *= i;
	}
	return fact;
}
void initializeMatrix(int** mas, size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			*(*(mas + i) + j) = factorial(i) + factorial(j);
		}
	}
}
void printMatrix(int** arr, size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cout.width(8);
			cout << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}
}
int* convertMatrixTo1DArray(int** mas, size_t rows, size_t cols, size_t length) {
	int* resultarray = new int[length];
	int pos = 0;
	for (size_t i = 1; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (i % 2 != 0) {
				*(resultarray + pos) = *(*(mas + i) + j);
				pos++;
			}
		}
	}
	return resultarray;
}
void printArray(int* arr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		cout << *(arr + i) << " ";
	}
}
int main() {
	const size_t rows = 5;
	const size_t cols = 5;
	const size_t length = 10;
	int** mas = new int* [rows];
	for (size_t i = 0; i < rows; i++) {
		*(mas + i) = new int[cols];
	}
	initializeMatrix(mas, rows, cols);
	cout << "Source matrix: " << endl;
	printMatrix(mas, rows, cols);
	int* arr = convertMatrixTo1DArray(mas, rows, cols, length);
	cout << "Result array: " << endl;
	printArray(arr, length);
	delete[] arr;
	for (int i = 0; i < rows; i++) {
		delete[] mas[i];
	}
	delete[] mas;
	return 0;
}
