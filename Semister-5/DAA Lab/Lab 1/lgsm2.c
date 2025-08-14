#include<stdio.h>
#include<stdlib.h>

int main (){
    FILE *fp= fopen("input.txt","r");
    if(fp == NULL){
        perror("Error opening the file");
        return 1;
    }
    int n;
    fscanf(fp,"%d","&n");

    int *arr = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        fscanf(fp,"%d",&arr[i]);
    }
    fclose(fp);
    int min =arr[0],second_min=__INT_MAX__;
    int max =arr[0],second_max=-__INT_MAX__;
    for (int i=1;i<n;i++){
        if(arr[i]<min){
            
        }
    }
}