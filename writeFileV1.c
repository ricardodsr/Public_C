#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The string to be written to the file
const char *str = "Temporary string to be written to file!";

/**
 * Main function.
 * Opens a file, writes the string to it, and closes the file.
 */
int main(void) {
    const char* filename = "out.txt";

    FILE* output_file;
    if (!(output_file = fopen(filename, "w+"))) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Write the string to the file
    if (fputs(str, output_file) == EOF) {
        perror("fputs");
        exit(EXIT_FAILURE);
    }

    printf("Done Writing!\n");

    fclose(output_file);
    exit(EXIT_SUCCESS);
}
