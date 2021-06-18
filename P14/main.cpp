#include <iostream>

using namespace std;

int reverse(int x){
    int res;
    int tmp;
    //자릿수를 이용해서
    
    while(x != 0){
        tmp = x % 10;
        x = x/10;
        res = (res*10) + tmp;
    }
    cout << "res :" << res;
    return res;
}

bool isPrime(int x){
    
    if(x < 2){
        return false;
    }
    
    for(int i = 2; i*i <= x; i++){ // 루트만큼 돌아도 괜찮음.
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    int N,x,i;
    int rev;
    bool prim;
    
    cin >> N;
    
    for(i = 0; i < N; i++){
        cin >> x;
        rev = reverse(x);
        if(isPrime(rev) == 1){
            cout << rev;
        }
    }
    
    return 0;
}
