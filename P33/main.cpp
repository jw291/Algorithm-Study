#include <iostream>
//스스로 해결!
int main() {
    int i,j,N,tmp,key,cnt = 0;
    int max = -2147000000;
    //원래는 key를 기준을 잡기 위한 변수로 썼는데
    //여기서 key는 비교대상 중 가장 작은 값이다.
    //기준은 i이다.
    int arr[100];
    
    scanf("%d",&N);
    for(i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    
    for(i = 0; i < N-1; i++){
        key = i;
        for(j = key; j < N; j++){
            if(arr[key] > arr[j]) key = j;
        }
        tmp = arr[key];
        arr[key] = arr[i];
        arr[i] = tmp;
    }
    
    for(i = 1; i < N; i++){
        if(arr[i-1] != arr[i]) cnt++; //어차피 정렬 돼어있으니까 이전값이랑 중복이 아니면 cnt해준다.
        if(cnt == 2){
            printf("%d\n",arr[i]);
            break;
        }
    }
    /*
    i = 0;
    while(cnt != 3){
        if(arr[i] > max) {
            max = arr[i];
            cnt++;
        }
        i++;
    }
    
    printf("%d",max);
     */
    
    return 0;
}
