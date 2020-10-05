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
	++array;
	cout << "\nPrefix increased vector:\n";
	array.printVector();
	array++;
	cout << "\nPostix increased vector:\n";
	array.printVector();	
	array--;
	cout << "\nPostfix decreased vector:\n";
	array.printVector();
	--array;
	cout << "\nPrefix decreased vector:\n";
	array.printVector();
	int rows, cols;
	cout << "\nEnter the number of rows in the matrix:\n";
	cin >> rows;
	cout << "\nEnter the number of coloumns in the matrix:\n";
	cin >> cols;
	Matrix m(rows, cols);
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
	++m;
	cout << "Prefix increased matrix:\n";
	m.printMatrix();
	m++;
	cout << "\nPostfix increased matrix:\n";
	m.printMatrix();
	m--;
	cout << "\nPostfix decreased matrix:\n";
	m.printMatrix();
	--m;
	cout << "\nPrefix decreased matrix:\n";
	m.printMatrix();
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
	Vector v(Nlength);
	v.getVectorFromMatrix(matrix);
	cout << "Result array: " << endl;
	v.printVector();
}
