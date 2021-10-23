#ifndef PROJECT_OBJECTORIENTED_H
#define PROJECT_OBJECTORIENTED_H

//------------------------------------------------------------------------------
// objectoriented.h - содержит описание объектно-ориентированный язык
//------------------------------------------------------------------------------

#include "rnd.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "programminglanguages.h"

//------------------------------------------------------------------------------
// объектно-ориентированный язык
class objectoriented : public programminglanguages {
public:
    enum Inheritance {
        SINGLE = 1,
        MULTIPLE,
        INTERFACE
    } inheritance;

//------------------------------------------------------------------------------
// Вывод параметров объектно-ориентированный язык в поток
    void Out(FILE *f) override;

    void In(FILE *f);

    void InRnd();

    objectoriented() : programminglanguages() {
        this->countname = 14;
    }
};

#endif //PROJECT_OBJECTORIENTED_H
