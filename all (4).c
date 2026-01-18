
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[5][10] = {"int", "float", "if", "else", "return"};

int isKeyword(char word[]) {
    for (int i = 0; i < 5; i++)
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[20];
    int i = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            buffer[i++] = ch;
        } else {
            buffer[i] = '\0';
            i = 0;

            if (strlen(buffer) > 0) {
                if (isKeyword(buffer))
                    printf("Keyword: %s\n", buffer);
                else
                    printf("Identifier: %s\n", buffer);
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
                printf("Operator: %c\n", ch);
        }
    }
    fclose(fp);
    return 0;
}