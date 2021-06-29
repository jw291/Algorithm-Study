//영상 봤음
#include <iostream>
#include <stack>

using namespace std;
int main() {
    int i,flag=1;
    stack<char> s;
    char a[50];
    
    scanf("%s",&a);
    
    for(i = 0; a[i] != '\0'; i++){
        if(a[i] == '(') s.push(a[i]);
        else {
            if(s.empty()) {
                printf("NO");
                flag = 0;
                break;
            }else s.pop();
        }
    }
    
    if(s.empty() && flag == 1) printf("YES");
    //위에서도 empty해서 NO찍고 또 YES찍을 우려가 있음.
    //그래서 위 상황과 아래 상황이 다르므로 flag로 구분함
    else if(!s.empty() && flag == 1) printf("NO");
    
    return 0;
}
