#ifndef PROJECT_OBJECTORIENTED_H
#define PROJECT_OBJECTORIENTED_H

//------------------------------------------------------------------------------
// objectoriented.h - содержит описание объектно-ориентированный язык
//------------------------------------------------------------------------------

#include "rnd.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

//------------------------------------------------------------------------------
// объектно-ориентированный язык
struct objectoriented {
    double tiobi;
    int yearofcreation;
    enum Inheritance {
        SINGLE = 1,
        MULTIPLE,
        INTERFACE
    } inheritance;

};

// Ввод параметров объектно-ориентированный язык из файла
void In(objectoriented *l, FILE *f);

// Случайный ввод параметров объектно-ориентированный язык
void InRnd(objectoriented *l);

// Вывод параметров объектно-ориентированный язык в форматируемый поток
void Out(objectoriented *l, FILE *f);

// Вычисление частное от деления года создания на количество символов в названии
double YearsDivideLetters(objectoriented *l);

#endif //PROJECT_OBJECTORIENTED_H
