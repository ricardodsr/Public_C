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

    FILE* output_file = fopen(filename, "w+");
    if (!output_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Write the string to the file
    fwrite(str, 1, strlen(str), output_file);

    printf("Done Writing!\n");

    fclose(output_file);
    exit(EXIT_SUCCESS);
}
