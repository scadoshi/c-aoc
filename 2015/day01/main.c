#include "../../common/utils.h"
#include "part1.h"
#include "part2.h"
#include <stdio.h>

int main() {
    // Read input file
    char *input = read_file("2015/day01/input.txt");
    if (!input) {
        fprintf(stderr, "Failed to read input file\n");
        return 1;
    }

    // Run both parts
    printf("Part 1: %d\n", part1(input));
    printf("Part 2: %d\n", part2(input));

    // Clean up
    free(input);
    return 0;
}
