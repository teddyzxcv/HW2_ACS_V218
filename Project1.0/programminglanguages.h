#ifndef PROJECT_PROGRAMMINGLANGUAGES_H
#define PROJECT_PROGRAMMINGLANGUAGES_H

//------------------------------------------------------------------------------
// programminglanguages.h - содержит описание обобщённого языки програмировании,
//------------------------------------------------------------------------------

#include "functional.h"
#include "objectoriented.h"
#include "procedural.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся виды языки программирование.
struct programminglanguages {
    // значения ключей для каждой из языки
    enum key {
        FUNCTIONAL, OBJECTORIENTED, PROCEDURAL
    };
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        objectoriented o;
        functional f;
        procedural p;
    };
};

// Ввод обобщенной язык
programminglanguages *In(int *size, FILE *f);

// Случайный ввод обобщенной язык
programminglanguages *InRnd();

// Вывод обобщенной язык
void Out(programminglanguages *languages, FILE *f);

// Вычисление частное от деления года создания на количество символов в названии
double YearsDivideLetters(programminglanguages *t);

#endif //PROJECT_PROGRAMMINGLANGUAGES_H
