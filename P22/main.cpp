#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N,K,i,j,sum = 0,max = -2147000000;
    
    scanf("%d %d", &N, &K);
    
    vector<int> d(N);
    for(i = 0; i < N; i++){
        scanf("%d",&d[i]);
    }
    
    for(i = 0; i < K; i++){
        sum += d[i];
    }
    
    max = sum;
    
    for(i = K; i < N; i++){
        sum = sum - d[i-K] + d[i];
        if(sum > max) max = sum;
    }
    
    /*
    for(i = 0; i < N-K; i++ ){
        for(j = i; j < K+i; j++){
            sum += d[j];
        }
        if(sum > max) {
            max = sum;
            sum = 0;
        }
    }*/
    
    printf("%d",max);
    return 0;
}
