#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n, i, j, cnt = 0;
    int arr[50001];
    
    scanf("%d",&n);
    
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j = j+i){ //i를 약수로 같는 숫자들은 i의 배수(i만큼 증가)이다.
                arr[j]++;//i를 약수로 같는 숫자 j번째 인덱스에 1씩 count한다.
        }
    }
    
    for(i = 1; i <= n; i++){
        printf("%d",arr[i]);
    }
    return 0;
}

