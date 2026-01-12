#include "utils.h"

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate buffer and read
    char *buffer = malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    fclose(file);
    return buffer;
}

char **read_lines(const char *filename, int *line_count) {
    char *content = read_file(filename);
    if (!content)
        return NULL;

    // Count lines
    int count = 0;
    for (char *p = content; *p; p++) {
        if (*p == '\n')
            count++;
    }
    if (content[strlen(content) - 1] != '\n')
        count++;

    // Allocate array
    char **lines = malloc(count * sizeof(char *));
    *line_count = count;

    // Split into lines
    int i = 0;
    char *line = strtok(content, "\n");
    while (line) {
        lines[i++] = strdup(line);
        line = strtok(NULL, "\n");
    }

    free(content);
    return lines;
}
