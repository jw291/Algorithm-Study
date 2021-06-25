#include <iostream>

int main() {
    char ch[10];
    int i, a = 0, b = 0, pos = 1, res;
    scanf("%s",&ch);
    
    if(ch[1] == 'H'){ //CH4에서 a찾기
        a = 1;
        pos = 2;
    }else{//C2H4에서 ab찾기 C2H에서 ab찾기
        
        for(i = pos; ch[i] != 'H'; i++){
            a = a*10 + (ch[i]-48);
        }
        
        pos = i+1;
        
    }
    
    if(ch[pos] == '\0'){
        b = 1;
    }else{
        for(i = pos; ch[i] != '\0'; i++){ // CH4에서 b찾기
            b = b*10 + (ch[i]-48);
        }
    }
    
    res = (12 * a) + (1 * b);
    
    printf("%d ",res);
     
    return 0;
}
