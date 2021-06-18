#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;
int main() {
    char str[30];
    int i , cnt =0;
    
    //카운트 하는 이유는
    //()))와 같이 )는 push를 하지 않기 때문에 empty라고 인식하기 때문에
    int opencount = 0; //열린 괄호 카운트
    int closecount = 0; //닫힌 괄호 카운트
    
    stack<char> s;
    scanf("%s",str);
    
    for(i = 1; str[i] != '\0'; i++){
        if(str[i] == '(')
        {
            s.push(str[i]);
            opencount++;
        }
        else if(str[i] == ')')
        {
            closecount++;
            if(!s.empty()){
                s.pop();
            }
        }
    }
    
    if(s.empty() && closecount > 0 && opencount > 0 && opencount == closecount)
        cout << "YES";
    else cout << "NO";
    
    return 0;
}
