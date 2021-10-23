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
        if ((this->cont[this->len] = Inlanguage(size, f)) != 0) {
            this->len++;
        }
    }
}

//------------------------------------------------------------------------------
// Ввод один язык.
programminglanguages *container::Inlanguage(int *size, FILE *f) {
    int k;
    fscanf(f, "%d", &k);
    switch (k) {
        case 1 : {
            functional *func = new functional();
            func->In(f);
            return func;
        }
        case 2: {
            objectoriented *objor = new objectoriented();
            objor->In(f);
            return objor;
        }
        case 3: {
            procedural *proc = new procedural();
            proc->In(f);
            return proc;
        }
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Ввод случайных элементов
void container::InRnd(int *size) {
    while (this->len < *size) {
        if ((this->cont[this->len] = InlanguageRnd(size)) != nullptr) {
            this->len++;
        }
    }
}

//------------------------------------------------------------------------------
// Ввод один рандомный язык.
programminglanguages *container::InlanguageRnd(int *size) {
    int k = Random(3);
    switch (k) {
        case 1 : {
            functional *func = new functional();
            func->InRnd();
            return func;
        }
        case 2: {
            objectoriented *objor = new objectoriented();
            objor->InRnd();
            return objor;
        }
        case 3: {
            procedural *proc = new procedural();
            proc->InRnd();
            return proc;
        }
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод всего, что в контейнере
void container::Out(FILE *f) {
    fprintf(f, "Container contains %d elements.\n", this->len);
    for (int i = 0; i < this->len; i++) {
        fprintf(f, "%d: ", i);
        this->cont[i]->Out(f);
    }
}

//------------------------------------------------------------------------------
// Сортировка бинарными вставками по убыванием.
void container::BinaryInsertion() {
    int i, loc, j;
    programminglanguages *selected;
    for (i = 1; i < this->len; ++i) {
        j = i - 1;
        selected = this->cont[i];
        loc = BinarySearch(selected, 0, j);
        while (j >= loc) {
            this->cont[j + 1] = this->cont[j];
            j--;
        }
        this->cont[j + 1] = selected;
    }
}

//------------------------------------------------------------------------------
// Бинарный поиск контейнера по частное от деления года создания на количество символов в названии
int container::BinarySearch(programminglanguages *item, int low, int high) {
    if (high <= low) {
        return (item->YearsDivideLetters() <
                this->cont[low]->YearsDivideLetters())
               ? (low + 1) : low;
    }
    int mid = (low + high) / 2;
    if (item->YearsDivideLetters() == this->cont[mid]->YearsDivideLetters()) {
        return mid + 1;
    }
    if (item->YearsDivideLetters() < this->cont[mid]->YearsDivideLetters()) {
        return BinarySearch(item, mid + 1, high);
    }
    return BinarySearch(item, low, mid - 1);
}

