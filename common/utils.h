#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read entire file into a string (caller must free)
char* read_file(const char* filename);

// Read file into lines array (caller must free array and each line)
char** read_lines(const char* filename, int* line_count);

#endif
