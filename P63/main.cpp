#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int map[19][19]; //전역을 안하면 초기화 해줘야함
    int n, m, a, b, c, i, j;
    
    scanf("%d %d", &n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &a ,&b, &c);
        map[a][b]=c;
    }
    
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
6 9
1 2 7
1 3 4
2 1 2
2 3 5
2 5 5
3 4 5
4 2 2
4 5 5
6 4 5
 */
