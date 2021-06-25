#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N, cnt2=0, cnt5=0, tmp ,i, j;
    
    scanf("%d",&N);
    
    for(i = 2; i <= N; i++){
        tmp = i;
        j = 2;
        while(1){
            if(tmp % j ==0){
                if(j == 2) cnt2++;
                else if(j == 5) cnt5++;
                
                tmp = tmp / j;
            }else j++;
            
            if(tmp == 1) break;
        }
    }
    
    if(cnt2 >= cnt5) printf("%d",cnt5);
    else printf("%d",cnt2);
    
    return 0;
}
