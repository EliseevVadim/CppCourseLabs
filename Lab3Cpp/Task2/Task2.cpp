#include <iostream>
#include "Conditioner.h"
#include "IControllable.h"
#include "Reflector.h"
/*Дополнить код задания 3 лабораторной работы № 2, написав еще два класса по предметной области, в соответствии с вариантом. Продумать и корректно реализовать схему наследования классов. В главной функции продемонстрировать применение интерфейса, полиморфизм и RTTI на примере 3-4 объектов классов, по аналогии с заданием 1.
Класс КОНДИЦИОНЕР + классы БЫТОВОЕ УСТРОЙСТВО, ОБОГРЕВАТЕЛЬ.
Реализовать схему наследования классов и корректно распределить по классам данные: фирма, модель, вес, температура, режим, год выпуска, мощность.
Интерфейс возможности управления / регулировки устройства IControllable с методом void control(int temperature) – отрегулировать устройство в зависимости от установленной в параметре температуры. Реализация метода в классе кондиционера: если температура задана меньше 10 градусов, то выдать сообщение и выключиться, иначе присвоить текущему режиму разный номер в зависимости от температуры (т.е. выставить режим). Реализация метода в классе обогревателя: если задана температура выше 45 градусов, то выдать сообщение и выключиться, иначе присвоить текущему режиму разный номер в зависимости от температуры. В main() создать 2 кондиционера и 1 обогреватель, продемонстрировать полиморфизм control(). 
*/
int main()
{
    HomeAppliance* applicances[3];
    applicances[0] = new Conditioner();
    applicances[0]->setWorkMode(WorkMode::ON);
    applicances[0]->setComfortableTemperature(25);
    applicances[1] = new Reflector("Panasonic", "06BD", 15, 30, WorkMode::ON, 35, 2005, 25);
    applicances[2] = new Conditioner();
    applicances[2]->setWorkMode(WorkMode::ON);
    applicances[2]->setComfortableTemperature(10);
    for (size_t i = 0; i < 3; ++i) {
        applicances[i]->control(8);
    }   
    std::cout << "______________________________________________________________________\n";
    std::cout << "Бытовые устройства:\n";
    for (size_t i = 0; i < 3; i++) {
        if (typeid(*applicances[i]) == typeid(Conditioner)) {
            std::cout << i+1 << ". Кондиционер\n";
        }
        else if (typeid(*applicances[i])==typeid(Reflector))
        {
            std::cout << i+1 << ". Оборгеватель\n";
        }
    }
    for (size_t i = 0; i < 3; i++) {
        delete applicances[i];
    }
}
