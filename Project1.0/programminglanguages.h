#ifndef PROJECT_PROGRAMMINGLANGUAGES_H
#define PROJECT_PROGRAMMINGLANGUAGES_H

//------------------------------------------------------------------------------
// programminglanguages.h - содержит описание обобщённого языки програмировании,
//------------------------------------------------------------------------------
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся виды языки программирование.
class programminglanguages {
    // значения ключей для каждой из языки
public:
    int countname;
    double tiobi;
    int yearofcreation;

// Вычисление частное от деления года создания на количество символов в названии
    double YearsDivideLetters() const;

    virtual void Out(FILE *f){

    }


};

#endif //PROJECT_PROGRAMMINGLANGUAGES_H
