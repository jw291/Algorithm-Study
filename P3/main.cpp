/*
 진약수의 합
 
 자연수 N이 주어지면 자연수 N의 진약수(자기 자신을 제외한 약수)의 합을 수식과 함께 출력하는 프로그램을 작성하세요
 
 입력
 첫 줄에 자연수 N이 주어진다.(3<N<= 100)
 
 출력
 첫 줄에 더하는 수식과 함께 합을 출력한다
 */
#include <iostream>

using namespace std;

int main() {
    int n,i, sum =1;
    
    cin >> n;
    
    cout << 1;
    for(i = 2; i < n; i++){
        if(n % i == 0){
            cout << "+" << i;
            sum += i;
        }
    }
    
    cout << "=" << sum;
    return 0;
}
