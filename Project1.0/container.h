#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H

#include "programminglanguages.h"

//------------------------------------------------------------------------------
// Инициализация
class container {
public:
    int len;
    programminglanguages **cont;

    //------------------------------------------------------------------------------
// Инициализация контейнера
    void Init(int *size);

// Полная очистка контейнера
    void Clear();

// Ввод в контейнер
    void In(int *size, FILE *f);

// Ввод случайных элементов
    void InRnd(int *size);

// Вывод всего, что в контейнере
    void Out(FILE *f);

// Сортировка бинарными вставками по убыванием.
    void BinaryInsertion();

// Бинарный поиск контейнера по частное от деления года создания на количество символов в названии
    int BinarySearch(programminglanguages *item, int l_border, int r_border);
};


#endif //PROJECT_CONTAINER_H
