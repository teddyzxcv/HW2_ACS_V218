#ifndef PROJECT_PROGRAMMINGLANGUAGES_H
#define PROJECT_PROGRAMMINGLANGUAGES_H

//------------------------------------------------------------------------------
// programminglanguages.h - содержит описание обобщённого языки програмировании,
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся виды языки программирование.
class programminglanguages {
    // значения ключей для каждой из языки
public:
    int countname;
    double tiobi;
    int yearofcreation;

// Вычисление частное от деления года создания на количество символов в названии
    double YearsDivideLetters();
};

#endif //PROJECT_PROGRAMMINGLANGUAGES_H
