#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
//2차원 배열 이쁘게 표현
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int n,i,j,k,cnt = 0,flag;
    
    scanf("%d",&n);
    
    vector<vector<int>> map(n+2, vector<int>(n+2,0));
    //n+2개의 element는 n+2개의 0으로 초기화된 element를 가진다.
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            flag = 0;
            for(k = 0; k < 4; k++){
                if (map[i][j] <= map[i+dx[k]][j+dy[k]]) {//dx dy 배열을 이용하여 상하좌우 알아내기
                    printf("aa[%d][%d] : %d\n",i,j,map[i][j]);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) cnt++;
            /*
            if((map[i][j] > map[i][j-1]) && (map[i][j] > map[i][j+1]) && (map[i][j] > map[i-1][j]) && (map[i][j] > map[i+1][j])){
                printf("a[%d][%d] : %d\n",i,j,map[i][j]);
                cnt++;
            }*/
        }
    }
    
    printf("%d",cnt);
    return 0;
}
