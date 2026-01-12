#include "part2.h"
#include <string.h>

int part2(const char *input) {
    int result = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(')
            result++;
        if (input[i] == ')')
            result--;
        if (result == -1)
            return i + 1;
    }
    return 0;
}
