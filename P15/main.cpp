#include <iostream>
//입력된 값보다 작은 소수의 개수 = 에라토스테네스의 체
using namespace std;
int main() {
    int N,cnt = 0;
    cin >> N;
    
    bool check[N+1];
    
    check[0] = check[1] = true;
    check[2] = check[3] = false;
    
    for(int i = 2; i*i <= N; i++){ //절반까지만 체크해도 상관없다.
        if(check[i] == true){
            continue;
        }
        
        for(int j = i+i; j<=N; j+=i){
            //2,3은 소수니까 4부터 배수 죽이기 시작
            //살아남은 값들, 그 누구의 배수도 아닌 값들이 곧 소수다
            check[j] = true;
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(!check[i]){
            cout << i <<" ";
        }
    }
    
    
    //cout << cnt;
    return 0;
}
