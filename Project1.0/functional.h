#ifndef PROJECT_FUNCTIONAL_H
#define PROJECT_FUNCTIONAL_H

//------------------------------------------------------------------------------
// functional.h - содержит описание функцианальный язык
//------------------------------------------------------------------------------

#include "rnd.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "programminglanguages.h"


//------------------------------------------------------------------------------
// функцианальный язык
//------------------------------------------------------------------------------

class functional : public programminglanguages {
public:
    enum Types {
        DYNAMIC = 1,
        STATIC = 2
    } type;
    bool isLazySupport;

    void Out(FILE *f) override;

    void In(FILE *f);

    void InRnd();

// Вывод параметров функцианальный язык в форматируемый поток
    functional() : programminglanguages() {
        this->countname = 10;
    }


};


#endif //PROJECT_FUNCTIONAL_H
