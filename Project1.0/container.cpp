#include "container.h"

//------------------------------------------------------------------------------
// Инициализация
void Init(container *c, int *size) {
    c->cont = new programminglanguages *[*size];
    c->len = 0;
}

//------------------------------------------------------------------------------
// Полная очистка контейнера
void Clear(container *c) {
    for (int i = 0; i < c->len; i++) {
        delete c->cont[i];
    }
    c->len = 0;
}

//------------------------------------------------------------------------------
// Ввод в контейнер
void In(container *c, int *size, FILE *f) {
    while (c->len < *size) {
        if ((c->cont[c->len] = In(size, f)) != 0) {
            c->len++;
        }
    }
}

//------------------------------------------------------------------------------
// Ввод случайных элементов
void InRnd(container *c, int *size) {
    while (c->len < *size) {
        if ((c->cont[c->len] = InRnd()) != nullptr) {
            c->len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод всего, что в контейнере
void Out(container *c, FILE *f) {
    fprintf(f, "Container contains %d elements.\n", c->len);
    for (int i = 0; i < c->len; i++) {
        fprintf(f, "%d: ", i);
        Out(c->cont[i], f);
    }
}

//------------------------------------------------------------------------------
// Сортировка бинарными вставками по убыванием.
void BinaryInsertion(container *c) {
    int i, loc, j;
    programminglanguages *selected;
    for (i = 1; i < c->len; ++i) {
        j = i - 1;
        selected = new programminglanguages;
        selected->k = c->cont[i]->k;
        if (selected->k == programminglanguages::FUNCTIONAL) { selected->f = c->cont[i]->f; }
        else if (selected->k == programminglanguages::OBJECTORIENTED) { selected->o = c->cont[i]->o; }
        else { selected->p = c->cont[i]->p; }
        loc = BinarySearch(c, selected, 0, j);
        while (j >= loc) {
            c->cont[j + 1] = c->cont[j];
            j--;
        }
        c->cont[j + 1] = selected;
    }
}

//------------------------------------------------------------------------------
// Бинарный поиск контейнера по частное от деления года создания на количество символов в названии
int BinarySearch(container *c, programminglanguages *item, int low, int high) {
    if (high <= low) {
        return (YearsDivideLetters(item) < YearsDivideLetters(c->cont[low])) ? (low + 1) : low;
    }
    int mid = (low + high) / 2;
    if (YearsDivideLetters(item) == YearsDivideLetters(c->cont[mid])) {
        return mid + 1;
    }
    if (YearsDivideLetters(item) < YearsDivideLetters(c->cont[mid])) {
        return BinarySearch(c, item, mid + 1, high);
    }
    return BinarySearch(c, item, low, mid - 1);
}

