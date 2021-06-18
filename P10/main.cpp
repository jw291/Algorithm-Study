#include <iostream>
#include <stdio.h>
using namespace std;


int digit_sum(int x){
    int res = 0;
    //10을 나눈 나머지는 첫번째 자릿수의 값을 구하는 방법
    //그다음 10을 나눠서 다음 자릿수의 값을 구하도록함.
    while(x != 0){
        res += (x % 10);
        x = x / 10;
    }
    return res;
}

int main() {
    int N, x, sum, res ,max = -2147000000;
    
    cin >> N;
    
    for(int i = 0; i <N; i++){
        cin >> x;
        
        sum = digit_sum(x);
        if(sum > max){
            max = sum;
            res = x;
        }else if(sum == max){
            if(x > res){
                res = x;
                
            }
        }
    }
    cout << res;
}
