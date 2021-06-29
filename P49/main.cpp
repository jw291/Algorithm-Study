//스스로해결
//커뮤니티에서 2차원배열 안쓰고 해결하는 방법도 있음

#include <stdio.h>
#include <vector>

using namespace std;
int main() {
    int N,i,j,idx=0;
    int res = 0;
    
    scanf("%d",&N);
    
    vector<vector<int>> block(N,vector<int>(N));
    
    int front[N];
    int r_side[N];
    
    for(i = 0; i < N; i++){
        scanf("%d",&front[i]);
    }
    
    for (i = 0; i < N; i++) {
        scanf("%d", &r_side[i]);
    }
    
    for(i = 0; i < N; i++){
        for(j = N-1; j >= 0; j--){
            if(front[i] <= r_side[j]){
                block[idx][i] = front[i];
            }else block[idx][i] = r_side[j];
            idx++;
        }
        idx = 0;
    }
    
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            res += block[i][j];
        }
    }
    
    printf("%d",res);
    
    return 0;
}
