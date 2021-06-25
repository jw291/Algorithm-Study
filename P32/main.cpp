#include <iostream>

int main() {
    int N,i,j,key,tmp;
    int arr[100];
    
    scanf("%d",&N);
    for(i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    
    for(i = 0; i < N-1; i++){
        key = i;
        
        for(j = key; j < N; j++){
            if(arr[key] > arr[j]){
                key = j; // 비교대상 중 작안 작은 값이 key에 들어감
            }
        }
        tmp = arr[key]; //i와 key를 바꿈
        arr[key] = arr[i];
        arr[i] = tmp;
    }
    
    for(i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
