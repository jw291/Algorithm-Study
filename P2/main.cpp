/*
 자연수의 합
 자연수 A,B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하세요.
 
 입력
 첫 줄에 자연수 A,B가 공백을 사이에 두고 차례대로 입력된다.(1<=-A<B<=100)
 
 출력
 첫 줄에 더하는 수식과 함께 합을 출력한다.
 */
#include <iostream>

using namespace std;

int main() {
    int a,b,i,sum = 0;
    
    cin >> a >> b;
    
    for(i = a; i < b; i++){
        cout << i << "+";
        sum = sum + i;
    }
    cout << i << "=";
    cout << sum+i;
    
    return 0;
}
