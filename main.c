#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 20
int is_palindrome_iter(char str[], int str_len);
int is_palindrome_rec(char str[], int str_len, char str_rec[], int i);

int main() {
    char* str = (char*) malloc(MAX_LENGTH *sizeof(char));
    int str_len, iter_is, rec_is, i = 0;
    char* str_rec = (char*) malloc(MAX_LENGTH *sizeof(char));
    printf("Hello, Please input your word so we can check if it is a palindrome:\n");
    scanf("%s", str);
    str_len = strlen(str);
    iter_is = is_palindrome_iter(str, str_len);
    rec_is = is_palindrome_rec(str, str_len, str_rec, i);
    if(iter_is == 0 && rec_is == 0)
        printf("The word '%s' is a palindrome.\n", str);
    else
        printf("The word '%s' is not a palindrome.\n", str);
    free(str), free(str_rec);
    return 0;
}

int is_palindrome_iter(char str[], int str_len){
    int result;
    char* str_iter = (char*) malloc(MAX_LENGTH *sizeof(char));
    for(int h = 0; h < str_len; h++){
        str_iter[h] = str[str_len - h - 1];
    }
    str_iter[str_len] = '\0';
    result = strcmp(str_iter, str);
    return result;
}

int is_palindrome_rec(char str[], int str_len, char str_rec[], int i){
    int result = 0;
    if(i != str_len){
        str_rec[i] =  str[str_len - i - 1];
        str_rec[i + 1] = '\0';
        is_palindrome_rec(str, str_len, str_rec, i + 1);
        return 0;
    }
    else if(i == str_len) {
        result = strcmp(str, str_rec);
        return result;
    }
    else
        return 0;
}