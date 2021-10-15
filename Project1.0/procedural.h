#ifndef PROJECT_PROCEDURAL_H
#define PROJECT_PROCEDURAL_H
//------------------------------------------------------------------------------
// procedural.h - содержит описание процедурный язык
//------------------------------------------------------------------------------

#include "rnd.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

//------------------------------------------------------------------------------
// процедурный язык
struct procedural {
    double tiobi;
    int yearofcreation;
    bool isAbstractTypeExist;
};

// Ввод параметров процедурный язык из файла
void In(procedural *l, FILE *f);

// Случайный ввод параметров процедурный язык
void InRnd(procedural *l);

// Вывод параметров процедурный язык в форматируемый поток
void Out(procedural *l, FILE *f);

// Вычисление частное от деления года создания на количество символов в названии
double YearsDivideLetters(procedural *l);

#endif //PROJECT_PROCEDURAL_H
