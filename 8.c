#include <stdio.h>

int main(){
    char word[1000];
    fgets(word,999,stdin);
    printf("%s" , word);
}