#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

void test(char text[]){
    char possible_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.:!?-'  ";
    char new_text[1000] = "";
    int count = 0;
    int position;
    char added_character;
    char text_character;
    while(strcmp(new_text,text) != 0){
        strcpy(new_text,"");
        for(int i = 0; i < strlen(text); i += 1){
            position = (rand() % strlen(possible_characters));
            text_character = text[i];
            added_character = possible_characters[position];
            if(text_character != added_character){
                break;
            }
            strncat(new_text, &added_character, 1);
        }
        count += 1;
        if(strlen(new_text) != 0){
            printf("%s\n",new_text);
        }
    }
    printf("Your text was generated in %d attempts.",count);
}

void main(){
    srand(time(NULL));
    char text[1000];
    printf("Text to be generated:");
    fgets(text,sizeof(text), stdin);
    
    size_t input_length = strlen(text);
    if (input_length > 0 && text[input_length - 1] == '\n') {
        text[input_length - 1] = '\0';
    }

    test(text);
}