#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkEmail(const char *adress);
int main() {
    char adress[30];

    printf("Enter ur email adress for validation ==> ");
    scanf("%29s",adress);

    int res = checkEmail(adress);

    if (res)
    {
        printf("Ur email adress is valid.");
    }else{
        printf("Ur email adress is invalid.");
    }
    
    return 0;
}

int checkEmail(const char *adress){
    const char *at = strchr(adress, '@');
    const char *dot = strrchr(adress, '.');

    if (at == NULL || dot == NULL)
    {
        return 0;
    }
    if (at>dot)
    {
        return 0;
    }
    
    for (const char *i = adress; i < at; i++) {
        if (!isalnum(*i) && *i != '_' && *i != '.') {
            return 0;
        }
    }

    for (const char *i = at + 1; i < dot; i++) {
        if (!isalpha(*i)) {
            return 0;
        }
    }
    const char* gmail = "gmail";
    if (strncmp(at + 1, gmail, strlen(gmail)) != 0 || at + 1 + strlen(gmail) != dot) {
    return 0;
    }

    for (const char *i = dot + 1; *i != '\0'; i++) {
        if (!isalpha(*i)) {
            return 0;
        }
    }
    const char* com = "com";
    if (strcmp(dot + 1,com) != 0)
    {
        return 0;
    }
    
    return 1;
}

