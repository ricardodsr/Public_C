#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
    const char* filename = "input.txt";

    FILE* input_file = fopen(filename, "r");
    if (!input_file)
        exit(EXIT_FAILURE);

    char *contents = NULL;
    size_t len = 0;
    while (getline(&contents, &len, input_file) != -1){
        printf("%s", contents);
    }

    fclose(input_file);
    free(contents);

    exit(EXIT_SUCCESS);
}