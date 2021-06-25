#include <iostream>

int main() {
    int N,i,j,tmp;
    
    int arr[100];
    
    scanf("%d",&N);
    
    for(i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    
    for(i = 1; i < N; i++){
        //tmp = i;로 하면 안쪽 for문에서 switching됐을 때 다른 값이 tmp가된다.
        //다른 정렬은 안쪽 for문에서 key와 비교만 해줬는데, 얘는 아예 값을 바꿔버려서 주의해야한다.
        //인덱스의 값으로 비교해야 하기 때문에 tmp = arr[i]
        tmp = arr[i];
        
        
        for(j = i-1; j >= 0; j--){
            if(arr[j] > tmp) arr[j+1] = arr[j];
            else break; // j-- 인덱스의 값이 key보다 크지 않다면 끝내버려도 된다.
            //어차피 그 이전인덱스 값들은 모두 정렬이 되어있기 때문이다.
        }
        
        arr[j+1] = tmp; // for문 바깥이라서 j--를 해버린 상태이기 때문에 j+1로 해야함
    }
    
    for(i = 0; i< N; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
