#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * Reads and prints the contents of a file.
 *
 * @param filename The name of the file to read.
 * @return 0 on success, -1 on error.
 */
#define BUFFER_SIZE 4096

int read_file(const char* filename) {
    FILE* input_file = fopen(filename, "r");
    if (!input_file)
        return -1;

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0){
        fwrite(buffer, sizeof(char), bytes_read, stdout);
    }

    fclose(input_file);
    return 0;
}

int main(void) {
    const char* filename = "input.txt";

    if (read_file(filename) != 0) {
        fprintf(stderr, "Failed to read file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    return 0;
}
