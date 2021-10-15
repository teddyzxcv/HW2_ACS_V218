//------------------------------------------------------------------------------
// programminglanguages.cpp - содержит процедуры связанные с обработкой обобщенной
// языки программирование и создания произвольной языки программировании.
//------------------------------------------------------------------------------

#include "programminglanguages.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной языки из файла
programminglanguages *In(int *size, FILE *f) {
    programminglanguages *language;
    int k;
    fscanf(f, "%d", &k);
    switch (k) {
        case 1:
            language = new programminglanguages;
            language->k = programminglanguages::FUNCTIONAL;
            In(&(language->f), f);
            return language;
        case 2:
            language = new programminglanguages;
            language->k = programminglanguages::OBJECTORIENTED;
            In(&(language->o), f);
            return language;
        case 3:
            language = new programminglanguages;
            language->k = programminglanguages::PROCEDURAL;
            In(&(language->p), f);
            return language;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Случайный ввод обобщенной языки
programminglanguages *InRnd() {
    programminglanguages *language;
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            language = new programminglanguages;
            language->k = programminglanguages::FUNCTIONAL;
            InRnd(&(language->f));
            return language;
        case 2:
            language = new programminglanguages;
            language->k = programminglanguages::OBJECTORIENTED;
            InRnd(&(language->o));
            return language;
        case 3:
            language = new programminglanguages;
            language->k = programminglanguages::PROCEDURAL;
            InRnd(&(language->p));
            return language;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей языки в поток
void Out(programminglanguages *language, FILE *f) {
    switch (language->k) {
        case programminglanguages::FUNCTIONAL:
            Out(&(language->f), f);
            break;
        case programminglanguages::OBJECTORIENTED:
            Out(&(language->o), f);
            break;
        case programminglanguages::PROCEDURAL:
            Out(&(language->p), f);
            break;
        default:
            fprintf(f, "Incorrect language!\n");
    }
}

//------------------------------------------------------------------------------
// Вычисление частное от деления года создания на количество символов в названии
double YearsDivideLetters(programminglanguages *language) {
    switch (language->k) {
        case programminglanguages::FUNCTIONAL:
            return YearsDivideLetters(&(language->f));
        case programminglanguages::OBJECTORIENTED:
            return YearsDivideLetters(&(language->o));
        case programminglanguages::PROCEDURAL:
            return YearsDivideLetters(&(language->p));
        default:
            return 0.0;
    }
}
