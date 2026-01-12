#include "part1.h"
#include <string.h>

int part1(const char *input) {
    int result = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(')
            result++;
        if (input[i] == ')')
            result--;
    }
    return result;
}
