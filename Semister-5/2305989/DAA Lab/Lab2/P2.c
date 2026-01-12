#include <stdio.h>

int findGCD(int temp1, int temp2)
{
    if((temp1 % temp2) == 0)
        return temp2;
    else
        return findGCD(temp2, (temp1 % temp2));
}

int main(int argc, char *args[])
{
    if(argc != 3)
    {
        printf("Give the input in the form <Source_File> <Destination_File> \n");
        return 0;
    }
    char *src = args[1];
    char *des = args[2];
    FILE *fp1, *fp2;
    int temp1, temp2, temp3;
    fp1 = fopen(src, "r");
    fp2 = fopen(des, "w");
    while(fscanf(fp1, "%d %d", &temp1, &temp2) == 2)
    {
        if(temp1 > temp2)
            temp3 = findGCD(temp1, temp2);
        else    
            temp3 = findGCD(temp2, temp1);
        fprintf(fp2, "%d \n", temp3);
        printf("GCD of %d and %d is %d \n", temp1, temp2, temp3);
    }
    return 0;
}