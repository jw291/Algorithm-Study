#include <iostream>
#include <stdio.h>

int main() {
    char str[101], copy[101];// \0까지 저장
    int i,p =0;
    //scanf("%s",str); 공백 입력 못받음
    gets(str);
    
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] != ' '){
            if(str[i] >=65 && str[i] <= 90)
            {
                copy[p++] = str[i] + 32;
            }else copy[p++] = str[i];
        }
    }
    copy[p] = '\0';
    printf("%s",copy);
    return 0;
}
