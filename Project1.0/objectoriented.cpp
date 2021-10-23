//------------------------------------------------------------------------------
// objectoriented.cpp - содержит функции обработки объектно-ориентированный язык
//------------------------------------------------------------------------------

#include "objectoriented.h"

//------------------------------------------------------------------------------
// Ввод параметров объектно-ориентированный язык из потока
void objectoriented::In(FILE *f) {
    int inheritance;
    fscanf(f, "%lf%d%i", &(this->tiobi), &(this->yearofcreation), &(inheritance));
    this->inheritance = static_cast<objectoriented::Inheritance>(inheritance);
}

// Случайный ввод параметров объектно-ориентированный язык
void objectoriented::InRnd() {
    this->tiobi = Random(100);
    this->yearofcreation = Random(2021);
    this->inheritance = static_cast<objectoriented::Inheritance>(Random(3));
}

//------------------------------------------------------------------------------
// Вывод параметров объектно-ориентированный язык в поток
void objectoriented::Out(FILE *f) {
    char inher[100] = "";
    switch (this->inheritance) {
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
            this->tiobi, this->yearofcreation,
            this->YearsDivideLetters(), inher);
}

