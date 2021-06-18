
#include <stdio.h>
#include <algorithm>
char A[60],B[60];
int main() {
    char str[100];
    int i;
    
    scanf("%s",&str);
    for(int i = 0; A[i] != '\0'; i++){
        if(str[i] >= 65 && str[i] <= 90){//소문자
            A[str[i] - 64]++; //해당 index에 count한다.
        }
        else if(str[i] >= 97 && str[i] <= 122){
            A[str[i] - 70]++; //해당 index에 count한다.
        }
    }
    
    scanf("%s",&str);
    for(int i = 0; B[i] != '\0'; i++){
        if(str[i] >= 65 && str[i] <= 90){//소문자
            B[str[i] - 64]++; //해당 index에 count한다.
        }
        else if(str[i] >= 97 && str[i] <= 122){
            B[str[i] - 70]++; //해당 index에 count한다.
        }
    }
    
    for(i =0; i<= 52; i++){
        if(A[i] != B[i]){
            printf("NO\n");
            exit(0);
        }
    }
    printf("Yes\n");
    return 0;
}
