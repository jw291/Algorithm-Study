#include <iostream>
//각자 공개할때마다 라운드 증가 10개의 카드(10라운드)
//숫자가 더 큰 사람이 이김 비기면 D
//이기면 3점 패자 0점 동점 1점
//총점이 같으면 마지막라운드에서 이긴 사람
//모든 라운드에서 비기면 비김

int main() {
    int A[10],B[10];
    int AP = 0 ,BP = 0,i;
    int rw = 0;
    //round winer를 체크하여 마지막에 누가 이겼는지를 알도록 함
    //이게 핵심
    
    for(i = 0; i < 10; i++){
        scanf("%d",&A[i]);
    }
    for(i = 0; i < 10; i++){
        scanf("%d",&B[i]);
    }
    
    for(i = 0; i < 10; i++){
        if(A[i] == B[i]){
            AP+=1;
            BP+=1;
        }
        else if(A[i] > B[i]) {AP+=3; rw=1; }
        else if(A[i] < B[i]) {BP+=3; rw=2; }
    }
    
    if(AP == BP){
        if(rw == 0) printf("D\n");
        else if(rw == 1) printf("A\n");
        else if(rw == 2) printf("B\n");
    }
    else if(AP > BP){ printf("%d %d\n",AP,BP); printf("A\n"); }
    else if(AP < BP){ printf("%d %d\n",AP,BP); printf("B\n"); }
    /*
    if(AP == 10 && BP == 10) printf("D\n");
    else if(AP > BP){ printf("%d %d\n",AP,BP); printf("A\n"); }
    else if(AP < BP){ printf("%d %d\n",AP,BP); printf("B\n"); }
    else if((AP != 10 && BP != 10) && AP == BP){
        if(rw == 1){
            printf("A\n");
        }else if(rw == 2){
            printf("B\n ");
        }
    }*/
    
    return 0;
}
