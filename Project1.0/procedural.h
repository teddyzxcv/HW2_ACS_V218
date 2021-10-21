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
#include "programminglanguages.h"

//------------------------------------------------------------------------------
// процедурный язык
class procedural : public programminglanguages {
public:
    bool isAbstractTypeExist;

// Ввод параметров процедурный язык из файла
    static void In(procedural *l, FILE *f);

// Случайный ввод параметров процедурный язык
    static void InRnd(procedural *l);

// Вывод параметров процедурный язык в форматируемый поток
   void Out(procedural *l, FILE *f);

// Вычисление частное от деления года создания на количество символов в названии
};


#endif //PROJECT_PROCEDURAL_H
