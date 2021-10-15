//------------------------------------------------------------------------------
// objectoriented.cpp - содержит функции обработки объектно-ориентированный язык
//------------------------------------------------------------------------------

#include "objectoriented.h"

//------------------------------------------------------------------------------
// Ввод параметров объектно-ориентированный язык из потока
void In(objectoriented *s, FILE *f) {
    int inheritance;
    fscanf(f, "%lf%d%i", &(s->tiobi), &(s->yearofcreation), &(inheritance));
    s->inheritance = static_cast<objectoriented::Inheritance>(inheritance);
}

// Случайный ввод параметров объектно-ориентированный язык
void InRnd(objectoriented *s) {
    s->tiobi = Random(100);
    s->yearofcreation = Random(2021);
    s->inheritance = static_cast<objectoriented::Inheritance>(Random(3));
}

//------------------------------------------------------------------------------
// Вывод параметров объектно-ориентированный язык в поток
void Out(objectoriented *s, FILE *f) {
    char inher[100] = "";
    switch (s->inheritance) {
        case 1:
            strcpy(inher, "Single");
            break;
        case 2:
            strcpy(inher, "Multiple");
            break;
        case 3:
            strcpy(inher, "Interface");
            break;
    }
    fprintf(f, "It is a object oriented language: TIOBI = %f. "
               "Year of creation = %d . Years divide count letters in the name = %f. Inheritance = %s\n",
            s->tiobi, s->yearofcreation,
            YearsDivideLetters(s), inher);
}

//------------------------------------------------------------------------------
// Вычисление частное от деления года создания на количество символов в названии
double YearsDivideLetters(objectoriented *s) {
    return double(double(s->yearofcreation) / 14);
}
