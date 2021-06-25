//병합정렬
#include <stdio.h>
#include <vector>
#include <algorithm>

//포인터 변수들 p1(a배열 1번) p2(b배열 1번) p3(c배열 1번)
//포인터 변수로 하나하나 비교함
//둘중 작은 값을 c에 넣었으면 작은 값이 있던 배열 포인터를 하나씩 증가시킴

int a[101], b[101], c[300];//넉넉하게

int main() {
    int n, m, i, p1 = 1, p2 = 1, p3 = 1;
    
    //입력
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &m);
    
    for(i = 1; i <= m; i++){
        scanf("%d", &b[i]);
    }
    
    while(p1 <= n && p2 <= m){
        if(a[p1] < b[p2]){
            c[p3++] = a[p1++];
        }
        else{
            c[p3++] = b[p2++];
        }
    }
    
    //남은거 쓸어담기
    while (p1 <= n) c[p3++] = a[p1++];
    while (p2 <= m) c[p3++] = b[p2++];
    
    //p3전까지인 이유는 위에서 집어넣고 또 증가햇으므로.
    for(i = 1; i < p3; i++)
        printf("%d ", c[i]);
    
    return 0;
}
