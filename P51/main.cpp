//2차원 배열 효율성 문제
//dp로 해결함
//dynamic table 생성함
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int H,W,n,m;
    int i,j,max = -2147000000, sum = 0;
    scanf("%d %d",&H, &W);
    vector<vector<int>> terri(H+1,vector<int>(W+1,0));
    vector<vector<int>> dt(H+1,vector<int>(W+1,0));//dynamic table
    
    for(i = 1; i <= H; i++){
        for(j = 1; j <= W; j++){
            scanf("%d", &terri[i][j]);
            dt[i][j] = terri[i-1][j] + terri[i][j-1] - terri[i-1][j-1] + terri[i][j];
        }
    }
    
    scanf("%d %d",&n,&m);
    
    for(i = n; i <= H; i++){
        for(j = m; j <= W; j++){
            sum = dt[i][j]-(dt[i-n][j]+dt[i][j-m]-dt[i-n][j-m]);
        }
        if(sum > max) max = sum;
    }
    
    printf("%d",max);
    
    return 0;
}
/*
6 7
3 5 1 3 1 3 2
1 2 1 3 1 1 2
1 3 1 5 1 3 4
5 1 1 3 1 3 2
3 1 1 3 1 1 2
1 3 1 3 1 2 2
2 3
 */
