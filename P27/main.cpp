#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N,i,j,tmp;
    
    scanf("%d",&N);
    
    vector<int> cnt(N+1);
    
    for(i = 2; i<= N; i++){
        tmp = i;
        j = 2;
        while(1){
            if(tmp % j == 0){
                tmp = tmp/j;
                cnt[j]++;
            }else j++;
                
            
            if(tmp == 1) break;
        }
            
    }
    
    printf("%d! = ", N);
    for(i = 2; i <= N; i++){
        if(cnt[i] != 0){
            printf("%d", cnt[i]);
        }
    }
    return 0;
}
