#include <iostream>
#include "DataManager.h"
int main()
{
    DataManager<int> manager;   
    manager.push(-9);
    int a[60] = { 0 };
    manager.push(a, 60);
    manager.print();
    int x = manager.peek();
    for (int i = 1; i < 15; ++i) {
        manager.push(i);
    }
    std::cout << "\n----------------------------------------------------------------------------------------------------\n";
    manager.print();
    x = manager.pop();
    std::cout << std::endl << "X = " << x << std::endl;
    std::cout << "\n----------------------------------------------------------------------------------------------------\n";
    std::cout << "Char Manager: \n";
    DataManager<char> char_manager;
    char_manager.push('h');
    char_manager.push('e');
    char_manager.push('l');
    char_manager.push('l');
    char_manager.push('o');
    char_manager.print();
    char ch = char_manager.popUpper();
    std::cout << "\nCh = " << ch << "\n";
    std::cout << "\n----------------------------------------------------------------------------------------------------\n";
    std::cout << "Double Manager: \n";
    DataManager<double> double_manager;
    double_manager.push(3.14);
    double_manager.push(0.5);
    double_manager.push(0.71);
    double_manager.push(3.16);
    double_manager.print();
    double y = double_manager.pop();
    std::cout << "\nY = " << y << "\n";
}