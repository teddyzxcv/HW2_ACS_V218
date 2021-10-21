#include "container.h"

//------------------------------------------------------------------------------
// Инициализация
void container::Init(int *size) {
    this->cont = new programminglanguages *[*size];
    this->len = 0;
}

//------------------------------------------------------------------------------
// Полная очистка контейнера
void container::Clear() {
    for (int i = 0; i < this->len; i++) {
        delete this->cont[i];
    }
    this->len = 0;
}

//------------------------------------------------------------------------------
// Ввод в контейнер
void container::In(int *size, FILE *f) {
    while (this->len < *size) {
        if ((this->cont[this->len] = programminglanguages::In(size, f)) != 0) {
            this->len++;
        }
    }
}

//------------------------------------------------------------------------------
// Ввод случайных элементов
void container::InRnd(int *size) {
    while (this->len < *size) {
        if ((this->cont[this->len] = programminglanguages::InRnd()) != nullptr) {
            this->len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод всего, что в контейнере
void container::Out(FILE *f) {
    fprintf(f, "Container contains %d elements.\n", this->len);
    for (int i = 0; i < this->len; i++) {
        fprintf(f, "%d: ", i);
        programminglanguages::Out(this->cont[i], f);
    }
}

//------------------------------------------------------------------------------
// Сортировка бинарными вставками по убыванием.
void container::BinaryInsertion() {
    int i, loc, j;
    programminglanguages *selected;
    for (i = 1; i < c->len; ++i) {
        j = i - 1;
        selected = new programminglanguages;
        selected->k = c->cont[i]->k;
        if (selected->k == programminglanguages::FUNCTIONAL) { selected->f = c->cont[i]->f; }
        else if (selected->k == programminglanguages::OBJECTORIENTED) { selected->o = c->cont[i]->o; }
        else { selected->p = this->cont[i]->p; }
        loc = BinarySearch(selected, 0, j);
        while (j >= loc) {
            c->cont[j + 1] = c->cont[j];
            j--;
        }
        c->cont[j + 1] = selected;
    }
}

//------------------------------------------------------------------------------
// Бинарный поиск контейнера по частное от деления года создания на количество символов в названии
int container::BinarySearch(programminglanguages *item, int low, int high) {
    if (high <= low) {
        return (programminglanguages::YearsDivideLetters(item) <
                programminglanguages::YearsDivideLetters(this->cont[low]))
               ? (low + 1) : low;
    }
    int mid = (low + high) / 2;
    if (programminglanguages::YearsDivideLetters(item) == programminglanguages::YearsDivideLetters(this->cont[mid])) {
        return mid + 1;
    }
    if (programminglanguages::YearsDivideLetters(item) < programminglanguages::YearsDivideLetters(this->cont[mid])) {
        return BinarySearch(item, mid + 1, high);
    }
    return BinarySearch(item, low, mid - 1);
}

