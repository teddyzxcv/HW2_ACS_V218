
#include "container.h"
#include "procedural.h"
#include "programminglanguages.h"

const char testroot[100] = "./../../TestInput/", resroot[100] = "./../../TestOutput/";

void error() {
    printf("Command line input error");
}

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    if (argc != 5) {
        error();
        return 1;
    }
    // Собираем адреса файлов.
    char testPath[200], resPath1[200], resPath2[200];
    strcpy(testPath, testroot);
    strcpy(resPath1, resroot);
    strcpy(resPath2, resroot);
    strcat(testPath, argv[2]);
    strcat(resPath1, argv[3]);
    strcat(resPath2, argv[4]);
    printf("Program started!\n");
    container *c = new container;
    FILE *f;
    int size;

    if (!strcmp(argv[1], "-f")) {
        f = fopen(testPath, "r");
        fscanf(f, "%d", &size);
        c->Init(&size);
        c->In(&size, f);
    } else if (!strcmp(argv[1], "-n")) {
        size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("Number of languages has to be between 1 and 10000");
            return 3;
        }
        c->Init(&size);
        srand(static_cast<unsigned int>(time(0)));
        c->InRnd(&size);
    } else {
        error();
        return 2;
    }

    // Вывод всех языки
    f = fopen(resPath1, "w+");
    fprintf(f, "Filled container:\n");
    c->Out(f);
    fclose(f);

    // Вывод отсортированных языки
    f = fopen(resPath2, "w+");
    fprintf(f, "Sorted container:\n");
    c->BinaryInsertion();
    c->Out(f);
    fclose(f);

    c->Clear();
    printf("Stop\n");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used: %.20f", cpu_time_used);
    return 0;
}

