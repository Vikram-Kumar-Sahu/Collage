#include<stdio.h>
#include<string.h>
int main(){
    char text1[50],text2[50];
    int c=0;
    printf("enter a string:");
    fgets(text1,50,stdin);
    text1[strcspn(text1,"\n")]='\0';
    char *str1=text1+strlen(text1)-1;
    char *str2=text2;
    while(str1>=text1){
        *(str2++)=*(str1--);
        
    }
    *str2 = '\0';
    puts(text2);
    return 0;
}
