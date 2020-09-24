#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
/*Елисеев Вадим, ИВТ-5, Вариант 7
Объявить массив из n=15 вещественных чисел, проинициализировать нулями. Функция processArray() должна заполнить массив случайными числами от 20.0 до 100.0, а затем вычесть из каждого элемента массива минимальное значение в массиве. Это значение она также должна вернуть на выходе. Сформировать выходной вещественный массив, в котором все элементы, стоящие до позиции минимального элемента включительно, повторяют элементы входного массива, а остальные равны минимальному элементу массива. Вывести на экран результирующие массивы.*/
int processArray(int mas[], int arr[], size_t length) {
    srand(time(NULL));
    int min = 101;
    int minindex;
    printf("Source array: \n");
    for (size_t i = 0; i < length; i++)
    {
        mas[i] = 20 + rand() % 81;
        if (min > mas[i]) {
            min = mas[i];
            minindex = i;
        }
        printf("%d ", mas[i]);
    }
    printf("\nOut array:\n");
    for (size_t i = 0; i < length; i++)
    {
        if (i < minindex) {
            arr[i] = mas[i];
        }
        else
        {
            arr[i] = min;
        }
        printf("%d ", arr[i]);
    }
    printf("\nArray after subtraction: \n");
    for (size_t i = 0; i < length; i++)
    {
        mas[i] -= min;
        printf("%d ", mas[i]);
    }
    return min;
}
int main()
{
    const size_t length = 15;
    int arr[length] = { 0 };
    int outarray[length];
    int minItem = processArray(arr, outarray, length);
    printf("\n");
    printf("Min item: %d", minItem);
    return 0;
    int a;
    cin >>a ;
}
