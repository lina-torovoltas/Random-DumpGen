#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>



int randint(int min, int max) {
    return rand() % (max - min + 1) + min;
}


// Generates a hexadecimal formatted dump with the specified number of lines and bytes per line.
void generate_hex_dump(uint64_t lines, uint64_t rows) {
    FILE *file = fopen("dump.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    for (uint64_t i = 0; i < lines; i++) {
        fprintf(file, "%08lx ", i);

        for (uint64_t j = 0; j < rows; j++) {
            uint8_t value = (uint8_t)randint(0, 255);
            fprintf(file, "%02X ", value);
        }

        fprintf(file, "\n");
    }

    fclose(file);
    printf("File dump.txt has been successfully generated in hexadecimal format.\n");
}


// Generates an octal formatted dump with the specified number of lines and values per line.
void generate_octal_dump(uint64_t lines, uint64_t rows) {
    FILE *file = fopen("dump.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    for (uint64_t i = 0; i < lines; i++) {
        fprintf(file, "%04lo ", i);

        for (uint64_t j = 0; j < rows; j++) {
            int value = randint(0, 63);
            fprintf(file, "%02o ", value);
        }

        fprintf(file, "\n");
    }

    fclose(file);
    printf("File dump.txt has been successfully generated in octal format.\n");
}



int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc != 2) {
        printf("Error: You need to specify a flag (-hex or -oct).\n");
        return 1;
    }

    char *flag = argv[1];
    uint64_t lines;
    uint64_t rows;

    printf("Enter the number of lines: ");
    if (scanf("%lu", &lines) != 1) {
        printf("Error: invalid input for lines.\n");
        return 1;
    }

    printf("Enter the number of rows per line: ");
    if (scanf("%lu", &rows) != 1) {
        printf("Error: invalid input for rows.\n");
        return 1;
    }

    if (strcmp(flag, "-hex") == 0) {
        if (lines > 4294967296) {
            printf("Error: Cannot create more than 4294967296 lines for hexadecimal dump.\n");
            return 1;
        }
        generate_hex_dump(lines, rows);
    }

    else if (strcmp(flag, "-oct") == 0) {
        if (lines > 4096) {
            printf("Error: Cannot create more than 4096 lines for octal dump.\n");
            return 1;
        }
        generate_octal_dump(lines, rows);
    } 
    
    else {
        printf("Error: Unknown flag %s.\n", flag);
        return 1;
    }

    return 0;
}