
#include "container.h"
#include "procedural.h"
#include "programminglanguages.h"

const char testroot[100] = "./../../TestInput/", resroot[100] = "./../../TestOutput/";

void error() {
    printf("Command line input error");
}

int main(int argc, char *argv[]) {
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
        Init(c, &size);
        In(c, &size, f);
    } else if (!strcmp(argv[1], "-n")) {
        size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("Number of languages has to be between 1 and 10000");
            return 3;
        }
        Init(c, &size);
        srand(static_cast<unsigned int>(time(0)));
        InRnd(c, &size);
    } else {
        error();
        return 2;
    }

    // Вывод всех языки
    f = fopen(resPath1, "w+");
    fprintf(f, "Filled container:\n");
    Out(c, f);
    fclose(f);

    // Вывод отсортированных языки
    f = fopen(resPath2, "w+");
    fprintf(f, "Sorted container:\n");
    BinaryInsertion(c);
    Out(c, f);

    Clear(c);
    printf("Stop\n");
    return 0;
}

