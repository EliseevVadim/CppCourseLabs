#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include "Book.h"
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    std::vector<Book*> books;
    books.push_back(new Book("����� � ���", "������� �.�.", 2010));
    books.push_back(new Book("���������", "����������� �.�.", 2004));
    books.push_back(new Book("�����", "�������� �.�.", 2010));
    books.push_back(new Book("���� ��������", "������� �.�.", 1999));
    books.push_back(new Book("������������ �������", "�������� �.�.", 2011));
    books.push_back(new Book("���������� �������", "������� �.", 2009));
    books.push_back(new Book("������ �����", "������� �.", 2001));
    books.push_back(new Book("�����", "ø�� �.�.", 2010));
    books.push_back(new Book("����� ������", "������� �.", 1998));
    std::vector<int> years = Book::createYearsVectorFromBooks(books);
    int count = std::count_if(years.begin(), years.end(), std::bind2nd(std::greater<int>(), 2009));
    std::cout << count;
    std::vector<Book*>::iterator i;
    for (i = books.begin(); i < books.end(); i++) {
        delete (*i);
    }
}