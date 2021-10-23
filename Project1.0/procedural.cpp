//------------------------------------------------------------------------------
// procedural.cpp - содержит функции обработки процедурный язык
//------------------------------------------------------------------------------

#include "procedural.h"

//------------------------------------------------------------------------------
// Ввод параметров процедурный язык из потока
void procedural::In(FILE *f) {
    int isAbstract = 0;
    fscanf(f, "%lf%d%d", &(this->tiobi), &(this->yearofcreation), &isAbstract);
    this->isAbstractTypeExist = isAbstract;
}

// Случайный ввод параметров процедурный язык
void procedural::InRnd() {
    this->tiobi = Random(100);
    this->yearofcreation = Random(2021);
    this->isAbstractTypeExist = Random(2) - 1;
}

//------------------------------------------------------------------------------
// Вывод параметров процедурный язык в поток
void procedural::Out(FILE *f) {
    char isAbstract[100] = "";
    if (this->isAbstractTypeExist) {
        strcpy(isAbstract, "Yes.\n");
    } else {
        strcpy(isAbstract, "No.\n");
    }
    fprintf(f, "It is a procedural language: TIOBI = %f. "
               "Year of creation = %d . Years divide count letters in the name = %f. Is abstract type exist = %s",
            this->tiobi, this->yearofcreation,
            this->YearsDivideLetters(), isAbstract);

}

