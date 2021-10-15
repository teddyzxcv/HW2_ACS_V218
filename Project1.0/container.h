#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H

#include "programminglanguages.h"

//------------------------------------------------------------------------------
// Инициализация
struct container {
    int len;
    programminglanguages **cont;
};

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container *c, int *size);

// Полная очистка контейнера
void Clear(container *c);

// Ввод в контейнер
void In(container *c, int *size, FILE *f);

// Ввод случайных элементов
void InRnd(container *c, int *size);

// Вывод всего, что в контейнере
void Out(container *c, FILE *f);

// Сортировка бинарными вставками по убыванием.
void BinaryInsertion(container *c);

// Бинарный поиск контейнера по частное от деления года создания на количество символов в названии
int BinarySearch(container *c, programminglanguages *item, int l_border, int r_border);


#endif //PROJECT_CONTAINER_H
