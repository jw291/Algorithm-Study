#include <iostream>

int main() {
    int N, i, j, tmp;
    
    int arr[100];
    
    scanf("%d",&N);
    
    for(i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    
    for(i = 0; i < N-1; i++){
        for(j = 1; j < N-i; j++){
            if(arr[j-1] > arr[j]){
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
    
    for(i = 0; i < N; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
