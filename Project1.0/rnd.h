#ifndef PROJECT_RND_H
#define PROJECT_RND_H

#include <cstdlib>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел в диапазоне от 1 до X
//------------------------------------------------------------------------------

inline auto Random(int x) {
    return rand() % x + 1;
}

#endif //PROJECT_RND_H
