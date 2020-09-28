#include <iostream>
#include "Vector.h";
#include <ctime>
#include "Matrix.h";
using namespace std;
/*Елисеев Вадим, ИВТ-5, Вариант 7
Написать классы Vector и Matrix для хранения и обработки одномерных и двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1 с помощью созданных классов. Все функции оформить в виде методов классов.
В коде отразить следующее:
 Выделение и освобождение динамической памяти производить в конструкторах и деструкторах классов, соответственно.
 В классе Vector перегрузить оператор индексации []. В классе Matrix добавить методы T at(int i, int j) const и setAt(int i, int j, T val), которые позволяют получить и установить значение элемента массива с индексом [i][j], T – это тип элементов массива по варианту (int или double).
 Перегрузить операторы инкремента и декремента (как префиксного, так и постфиксного). Смысл инкремента / декремента всего массива заключается в инкременте / декременте каждого элемента массива.*/
int main()
{
	srand(time(NULL));
	int length;
	cout << "Enter the length of vector\n";
	cin >> length;
	Vector array(length);
	for (int i = 0; i < length; i++) {
		array[i] = rand() % 101;
	}
	cout << "The source vector:\n";
	array.printVector();
	int index;
	cout << "\nEnter the index for getting\n";
	cin >> index;
	int res = array[index];
	if (res != NULL) {
		cout << "The founded element is: " << res << endl;
	}
	else
	{
		cout << "The founded element is nothing\n";
	}
	Vector bufPrefInc = ++array;
	cout << "\nPrefix increased vector:\n";
	array.printVector();
	Vector buffPostInc = array++;
	cout << "\nPostix increased vector:\n";
	array.printVector();	
	Vector buffPostDec = array--;
	cout << "\nPostfix decreased vector:\n";
	array.printVector();
	Vector buffPrefDec = --array;
	cout << "\nPrefix decreased vector:\n";
	array.printVector();
	array.~Vector();
	int rows, cols;
	cout << "\nEnter the number of rows in the matrix:\n";
	cin >> rows;
	cout << "\nEnter the number of coloumns in the matrix:\n";
	cin >> cols;
	Matrix m(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m.setAt(i, j, rand() % 100);
		}
	}
	cout << "\nThe source matrix:\n";
	m.printMatrix();
	int i, j;
	cout << "Enter the row and coloumn index of element for getting:\n";
	cin >> i >> j;
	int result = m.at(i, j);
	if (result != NULL) {
		cout << "The founded element is: " << result << endl;
	}
	else
	{
		cout << "The founded element is nothing\n";
	}
	Matrix buffPrefIncM = ++m;
	cout << "Prefix increased matrix:\n";
	m.printMatrix();
	Matrix buffPostIncM = m++;
	cout << "\nPostfix increased matrix:\n";
	m.printMatrix();
	Matrix buffPostDecM = m--;
	cout << "\nPostfix decreased matrix:\n";
	m.printMatrix();
	Matrix buffPrefDecM = m--;
	cout << "\nPrefix decreased matrix:\n";
	m.printMatrix();
	m.~Matrix();
	cout << "\nTask from the first lab (variant 7)\n";
	const int Nrows = 5;
	const int Ncols = 5;
	const int Nlength = 10;
	Matrix matrix(5, 5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrix.setAt(i, j, matrix.factorial(i) + matrix.factorial(j));
		}
	}
	cout << "Source matrix: " << endl;
	matrix.printMatrix();
	Vector vector(Nlength);
	int pos = 0;
	for (int i = 1; i < Nrows; i++) {
		for (int j = 0; j < Ncols; j++) {
			if (i % 2 != 0) {
				vector[pos]=matrix.at(i, j);
				pos++;
			}
		}
	}
	cout << "Result array: " << endl;
	vector.printVector();	
}
