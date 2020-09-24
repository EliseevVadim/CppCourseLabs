#include <iostream>
#include "Stadium.h"
#include <ctime>
#define RAND_MAX 0x7ffff
/* Елисеев Вадим, ИВТ-5, Вариант 7
Написать собственный класс, в соответствии с вариантом. Продемонстрировать в коде инкапсуляцию данных, применение конструкторов без параметров и с параметрами для инициализации данных. Класс должен содержать метод serialize() для сохранения данных класса в файл и метод deserialize() для чтения данных класса из файла по умолчанию в текущей директории, а также перегруженные методы serialize(const std::string& filename) и deserialize(const std::string& filename) для работы с файлом с указанным в параметре именем.
Класс СТАДИОН.
Данные: адрес, футбольный клуб, количество секторов, вместимость, посещаемость.
Создать 2 стадиона в куче и один в стеке. Установить данные первых двух с помощью сеттеров, данные третьего установить в конструкторе с параметрами. В главной функции проимитировать четыре матча – случайным образом сформировать количество пришедших посетителей и просчитать процент заполнения каждого стадиона. Вывести информацию о стадионах, отсортировав их в порядке убывания среднего процента заполнения за четыре матча.*/
int main()
{
    srand(time(NULL));
    setlocale(0, "Russian");
    Stadium* st1 = new Stadium;
    st1->setClub("Спартак");
    st1->setLoc("г. Москва");
    st1->setSectorsNumber(12);
    st1->setComplexity(85000);
    Stadium* st2 = new Stadium;
    st2->setClub("Шахтер");
    st2->setLoc("г. Донецк");
    st2->setSectorsNumber(10);
    st2->setComplexity(79000);
    Stadium st3("г. Екатеринбург", "Зенит", 14, 93000);
    float first_stad_percents[4];
    float averages[3] = {0};
    for (int i = 0; i < 4; i++) {
        int rv = (RAND_MAX -rand()) % 85000;
        st1->setAttendance(rv);
        first_stad_percents[i] = st1->getPercent();  
        averages[0] += first_stad_percents[i];
    }
    st1->setAverageValue(averages[0] / 4);
    float second_stad_percents[4];
    for (int i = 0; i < 4; i++) {
        int rv = (RAND_MAX - rand()) % 79000;
        st2->setAttendance(rv);
        second_stad_percents[i] = st1->getPercent();
        averages[1] += second_stad_percents[i];
    }
    st2->setAverageValue(averages[1] / 4);
    float third_stad_percents[4];
    for (int i = 0; i < 4; i++) {
        int rv = (RAND_MAX - rand()) % 93000;
        st3.setAttendance(rv);
        third_stad_percents[i] = st3.getPercent();
        averages[2] += third_stad_percents[i];
    }
    st3.setAverageValue(averages[2] / 4);
    Stadium stads[3];
    stads[0] = *st1;
    stads[1] = *st2;
    stads[2] = st3;
    for (int i = 0; i < 3; i++) {
        int max = i;
        for (int j = i + 1; j < 3; j++) {
            if (stads[j].getAverageValue() > stads[max].getAverageValue()) {
                max = j;
            }
        }
        std::swap(stads[max], stads[i]);
    }
    for (int i = 0; i < 3; i++) {
        stads[i].printInfo();
    }
    delete st1;
    delete st2;
}  