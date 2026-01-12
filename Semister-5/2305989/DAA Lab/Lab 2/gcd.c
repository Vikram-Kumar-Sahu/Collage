#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char *srcFile = argv[1];
    char *destFile = argv[2];

    FILE *src = fopen(srcFile, "r");
    if (src == NULL)
    {
        perror("Error opening source file");
        return 1;
    }

    FILE *dest = fopen(destFile, "w");
    if (dest == NULL)
    {
        perror("Error opening destination file");
        fclose(src);
        return 1;
    }

    int a, b;
    int count = 0;

    while (fscanf(src, "%d %d", &a, &b) == 2)
    {
        int result = gcd(a, b);
        fprintf(dest, "GCD of %d and %d is %d\n", a, b, result);
        count++;
    }

    if (count < 3)
    {
        printf("Warning: Less than 20 pairs found in input file. Found %d pairs.\n", count);
    }

    fclose(src);
    fclose(dest);

    printf("GCDs written to '%s'. Total pairs processed: %d\n", destFile, count);

    return 0;
}
