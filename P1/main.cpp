/*
 1부터 N까지의 M의 배수합
 자연수 N이 입력되면 1부터 N까지의 수 중 M의 배수합을 출력하는 프로그램
 
 입력
 첫 줄에 자연수 N과 M이 차례대로 입력된다.(3<=M<N<=1000)
 
 출력
 첫 줄에 M의 배수합을 출력한다.
 */
#include <iostream>

using namespace std;
int main() {
    int n,m,i, sum = 0;
    cout << "입력 : ";
    cin >> n >> m;
    
    for(i = 1; i <= n; i++){
        if(i % 3 == 0){
            sum = sum + i;
        }
    }
    
    cout << "결과 : " << sum;
    
    return 0;
}
