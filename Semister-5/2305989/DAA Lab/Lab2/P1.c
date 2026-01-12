#include <stdio.h>

long ConvertToBinary(int temp)
{
    if(temp == 0)
        return 0;
    else
    {    
        return ((temp % 2) + (10 * ConvertToBinary(temp / 2)));
    }
}

int main()
{
    int n, temp;
    char src[100], des[100];
    FILE *fp1, *fp2;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the name of Source file: ");
    scanf("%s", src);
    printf("Enter the name of Destination file: ");
    scanf("%s", des);
    fp1 = fopen(src, "r");
    fp2 = fopen(des, "w");
    if(fp1 == NULL || fp2 == NULL)
    {
        printf("Error opening input or output file \n");
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        fscanf(fp1, "%d", &temp);
        long temp2 = ConvertToBinary(temp);
        fprintf(fp2, "%ld \n", temp2);
        printf("Binary Equivalent of %d is %ld \n", temp, temp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}