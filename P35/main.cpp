//스스로 해결!
//버블정렬의 stable함과
//차근차근 올라가는 특성을 이용함
#include <iostream>

int main(int argc, const char * argv[]) {
    int N,i,j,tmp;
    int arr[100];
    
    scanf("%d",&N);
    
    for(i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    
    for(i = 0; i < N-1; i++){
        for(j = 1; j < N-i; j++){
            if(arr[j-1] > 0 && arr[j] < 0){
                tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    
    for(i = 0; i < N; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
