#include <stdio.h>

int main(int argc, char *argv[]) {
    // Check if file names are provided
    if (argc < 2) {
        printf("Usage: %s <filename1> [<filename2> ... <filenameN>]\n", argv[0]);
        return 1;
    }

    // Iterate through each provided file name
    for (int i = 1; i < argc; i++) {
        // Open the file in write mode
        FILE *file = fopen(argv[i], "w");

        // Check if the file is opened successfully
        if (file == NULL) {
            printf("Error: Unable to open file '%s'.\n", argv[i]);
            continue;
        }

        // Erase the content by truncating the file
        fclose(file);

        printf("Content of '%s' has been erased.\n", argv[i]);
    }

    return 0;
}
