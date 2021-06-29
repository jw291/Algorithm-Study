//스스로 해결 검토필요x
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int H,W;
    int t_H,t_W;
    int i,j,k,p, max = -2147000000, sum = 0;
    
    scanf("%d %d",&H, &W);
    
    vector<vector<int>> terri(H,vector<int>(W));
    
    for(i = 0; i < H; i++){
        for (j = 0; j < W; j++) {
            scanf("%d",&terri[i][j]);
        }
    }
    
    scanf("%d %d",&t_H,&t_W);
    
    for(i = 0; i <= H-t_H; i++){
        for (j = 0; j <= W-t_W; j++) {
            sum = 0;
            for(k = i; k < i+t_H; k++){
                for(p = j; p < j+t_W; p++){
                    sum += terri[k][p];
                }
            }
            if(sum > max) max = sum;
        }
    }
    
    printf("%d",max);
    
    return 0;
}
/*
3 5 1 3 1 3 2
1 2 1 3 1 1 2
1 3 1 5 1 3 4
5 1 1 3 1 3 2
3 1 1 3 1 1 2
1 3 1 3 1 2 2
 */
