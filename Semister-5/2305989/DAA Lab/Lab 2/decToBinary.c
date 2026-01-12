#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive helper to build binary string using index
void helper(int val, char *bin, int *idx) {
    if (val == 0) return;
    helper(val / 2, bin, idx);
    bin[(*idx)++] = (val % 2) + '0';  // Convert digit to char
}

// Main converter
void decToBin(int value, char *binary) {
    if (value == 0) {
        strcpy(binary, "0");
        return;
    }
    int idx = 0;
    helper(value, binary, &idx);
    binary[idx] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *srcFile = argv[2];
    char *destFile = argv[3];

    FILE *src = fopen(srcFile, "r");
    if (src == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *dest = fopen(destFile, "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return 1;
    }

    int value, count = 0;
    while (count < n && fscanf(src, "%d", &value) == 1) {
        char binary[100] = "";
        decToBin(value, binary);
        fprintf(dest, "%d %s\n", value, binary);
        count++;
    }

    fclose(src);
    fclose(dest);

    // Displaying output file content
    FILE *output = fopen(destFile, "r");
    if (output == NULL) {
        perror("Error opening output file for reading");
        return 1;
    }

    printf("\nDecimal to Binary Output:\n");
    int dec;
    char bin[100];
    while (fscanf(output, "%d %s", &dec, bin) == 2) {
        printf("Decimal: %d => Binary: %s\n", dec, bin);
    }

    fclose(output);
    return 0;
}
