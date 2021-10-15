//------------------------------------------------------------------------------
// functional.cpp - содержит функции обработки функцианальный язык
//------------------------------------------------------------------------------

#include "functional.h"

//------------------------------------------------------------------------------
// Ввод параметров функцианальный язык из потока
void In(functional *s, FILE *f) {
    int type;
    int isLazy = 0;
    fscanf(f, "%lf%d%i%i", &(s->tiobi), &(s->yearofcreation), &(type), &(isLazy));
    s->isLazySupport = isLazy;
    s->type = static_cast<functional::Types>(type);
}

//------------------------------------------------------------------------------
// Случайный ввод параметров функцианальный язык
void InRnd(functional *s) {
    s->tiobi = Random(100);
    s->yearofcreation = Random(2021);
    s->type = static_cast<functional::Types>(Random(2));
    s->isLazySupport = Random(2) - 1;
}

//------------------------------------------------------------------------------
// Вывод параметров функцианальный язык в поток
void Out(functional *s, FILE *f) {
    char type[100], lazy[100] = "";
    switch (s->type) {
        case 1:
            strcpy(type, "Dynamic");
            break;
        case 2:
            strcpy(type, "Static");
            break;
    }
    if (!s->isLazySupport) {
        strcpy(lazy, "No");
    } else {
        strcpy(lazy, "Yes");
    }
    fprintf(f, "It is a functional language: TIOBI = %f. "
               "Year of creation = %d . Years divide count letters in the name = %f. Type = %s. Is lazy calculation support = %s\n",
            s->tiobi, s->yearofcreation,
            YearsDivideLetters(s), type, lazy);
}

//------------------------------------------------------------------------------
// Вычисление частное от деления года создания на количество символов в названии
double YearsDivideLetters(functional *s) {
    return double(double(s->yearofcreation) / 10);
}
