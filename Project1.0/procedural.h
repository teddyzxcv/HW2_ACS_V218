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

//------------------------------------------------------------------------------
// Вывод параметров процедурный язык в поток
    void Out(FILE *f) override;


    void In(FILE *f);

    void InRnd();

    procedural() : programminglanguages() {
        this->countname = 10;
    }
};


#endif //PROJECT_PROCEDURAL_H
