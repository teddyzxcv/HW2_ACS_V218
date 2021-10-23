//------------------------------------------------------------------------------
// functional.cpp - содержит функции обработки функцианальный язык
//------------------------------------------------------------------------------

#include "functional.h"

//------------------------------------------------------------------------------
// Ввод параметров функцианальный язык из потока
void functional::In(FILE *f) {
    int type;
    int isLazy = 0;
    fscanf(f, "%lf%d%i%i", &(this->tiobi), &(this->yearofcreation), &(type), &(isLazy));
    this->isLazySupport = isLazy;
    this->type = static_cast<functional::Types>(type);
}

void functional::InRnd() {
    this->tiobi = Random(100);
    this->yearofcreation = Random(2021);
    this->type = static_cast<functional::Types>(Random(2));
    this->isLazySupport = Random(2) - 1;
}

//------------------------------------------------------------------------------
// Вывод параметров функцианальный язык в поток
void functional::Out(FILE *f) {
    char type[100], lazy[100] = "";
    switch (this->type) {
        case 1:
            strcpy(type, "Dynamic");
            break;
        case 2:
            strcpy(type, "Static");
            break;
    }
    if (!this->isLazySupport) {
        strcpy(lazy, "No");
    } else {
        strcpy(lazy, "Yes");
    }
    fprintf(f, "It is a functional language: TIOBI = %f. "
               "Year of creation = %d . Years divide count letters in the name = %f. Type = %s. Is lazy calculation support = %s\n",
            this->tiobi, this->yearofcreation,
            this->YearsDivideLetters(), type, lazy);
}

