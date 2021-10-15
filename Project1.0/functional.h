#ifndef PROJECT_FUNCTIONAL_H
#define PROJECT_FUNCTIONAL_H

//------------------------------------------------------------------------------
// functional.h - содержит описание функцианальный язык
//------------------------------------------------------------------------------

#include "rnd.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"


//------------------------------------------------------------------------------
// функцианальный язык
//------------------------------------------------------------------------------

struct functional {
    double tiobi;
    int yearofcreation;
    enum Types {
        DYNAMIC = 1,
        STATIC = 2
    } type;
    bool isLazySupport;
};

//------------------------------------------------------------------------------
// Ввод параметров функцианальный язык из файла
void In(functional *l, FILE *f);

// Случайный ввод параметров функцианальный язык
void InRnd(functional *l);

// Вывод параметров функцианальный язык в форматируемый поток
void Out(functional *l, FILE *f);

// Вычисление частное от деления года создания на количество символов в названии
double YearsDivideLetters(functional *l);

#endif //PROJECT_FUNCTIONAL_H
