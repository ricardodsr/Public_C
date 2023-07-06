#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 8192

/**
 * Reads and prints the contents of a file.
 *
 * @param filename The name of the file to read.
 * @return 0 on success, -1 on error.
 */
int read_file(const char* filename) {
    FILE* input_file = fopen64(filename, "r");
    if (!input_file)
        return -1;

    char* contents = (char*)malloc(BUFFER_SIZE);
    if (!contents) {
        fclose(input_file);
        return -1;
    }

    size_t total_size = 0;
    size_t buffer_size = BUFFER_SIZE;
    char* line = contents;

    while (1) {
        if (getline(&line, &buffer_size, input_file) == -1)
            break;

        printf("%s", line);
        total_size += buffer_size;

        if (total_size + buffer_size >= buffer_size) {
            buffer_size *= 2;
            contents = (char*)realloc(contents, buffer_size);
            if (!contents) {
                fclose(input_file);
                return -1;
            }
            line = contents + total_size;
        }
    }

    fclose(input_file);
    free(contents);

    return 0;
}

int main(void) {
    const char* filename = "input.txt";

    if (read_file(filename) != 0) {
        fprintf(stderr, "Failed to read file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
