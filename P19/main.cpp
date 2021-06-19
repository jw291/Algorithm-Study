#include <iostream>
#include <stdio.h>

int main() {
    int n, i, cnt = 0, h[101], max;
    scanf("%d",&n);
    
    for(i = 1; i <= n; i++){
        scanf("%d",  &h[i]);
    }
    
    max = h[n]; // 배열에서 max활용하기
    //뒤에서부터 비교할 것이므로 맨 뒤의 값을 max로 잡는다.
    
    for(i = n-1; i >= 1; i--){ //뒤에서부터 체크한다.
        if(h[i] > max){ //max보다 그 다음 인덱스가 크면
            max = h[i];
            cnt++; //카운트 하나 올린다.
        }
    }
    
    printf("%d\n",cnt);
    
    return 0;
    /*
    int N , i, j, num, cnt2 = 0,cnt = 0;
    int stu[100];
    //max를 이용하면 한번만 돌아도 구할 수 있는데
    //이건 2중 for문을 써야할 것 같음
    
    scanf("%d",&N);
    
    for(i = 0; i < N; i++){
        scanf("%d",&stu[i]);
    }
    
    for(i = 0; i < N-1; i++){
        num = (N-1) - i;
        
        for(j = i+1; j < N; j++){
            if(stu[i] > stu[j]) cnt++;
        }
 
        if(cnt == num) cnt2++;
        
        cnt = 0;
    }
    
    printf("%d",cnt2);
    
    return 0;
     */
}
