//------------------------------------------------------------------------------
// procedural.cpp - содержит функции обработки процедурный язык
//------------------------------------------------------------------------------

#include "procedural.h"

//------------------------------------------------------------------------------
// Ввод параметров процедурный язык из потока
void procedural::In(procedural *s, FILE *f) {
    int isAbstract = 0;
    fscanf(f, "%lf%d%d", &(s->tiobi), &(s->yearofcreation), &isAbstract);
    s->isAbstractTypeExist = isAbstract;
}

// Случайный ввод параметров процедурный язык
void procedural::InRnd(procedural *s) {
    s->tiobi = Random(100);
    s->yearofcreation = Random(2021);
    s->isAbstractTypeExist = Random(2) - 1;
}

//------------------------------------------------------------------------------
// Вывод параметров процедурный язык в поток
void procedural::Out(procedural *s, FILE *f) {
    char isAbstract[100] = "";
    if (s->isAbstractTypeExist) {
        strcpy(isAbstract, "Yes.\n");
    } else {
        strcpy(isAbstract, "No.\n");
    }

    fprintf(f, "It is a procedural language: TIOBI = %f. "
               "Year of creation = %d . Years divide count letters in the name = %f. Is abstract type exist = %s",
            s->tiobi, s->yearofcreation,
            YearsDivideLetters(s), isAbstract);

}

//------------------------------------------------------------------------------
// Вычисление частное от деления года создания на количество символов в названии
double procedural::YearsDivideLetters(procedural *s) {
    return double(double(s->yearofcreation) / 14);
}
