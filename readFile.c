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
int read_file(const char* filename) {
    FILE* input_file = fopen(filename, "r");
    if (!input_file)
        return -1;

    char *contents = NULL;
    size_t len = 0;
    while (getline(&contents, &len, input_file) != -1){
        printf("%s", contents);
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
