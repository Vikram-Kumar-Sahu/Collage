#include <stdio.h>
#include <stdlib.h>

void findDuplicates(int *arr, int n) 
{
    int duplicateCount = 0;
    int maxCount = 0, mostRepeating = arr[0];
    int *visited = (int*)calloc(n, sizeof(int));

    printf("The content of the array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        if(visited[i]) 
            continue;
        int count = 1;
        for(int j = i + 1; j < n; j++)  
        {
            if(arr[i] == arr[j]) 
            {
                count++;
                visited[j] = 1;
            }
        }
        if(count > 1) 
            duplicateCount += count - 1;
        if(count > maxCount) 
        {
            maxCount = count;
            mostRepeating = arr[i];
        }
    }

    printf("Total number of duplicate values = %d\n", duplicateCount);
    printf("The most repeating element in the array = %d\n", mostRepeating);

    free(visited);
}

int main() 
{
    int n;
    FILE *file;
    file = fopen("Numbers.txt", "r");
    if(file == NULL) 
    {
        printf("Error while opening file!\n");
        return 1;
    }
    fscanf(file, "%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        fscanf(file, "%d", &arr[i]);
    findDuplicates(arr, n);
    free(arr);
    fclose(file);
    return 0;
}