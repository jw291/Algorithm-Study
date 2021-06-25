//삽입정렬 스타일 보면
//배열에서 자기보다 앞에있는 인덱스의 모든 수를
//비교해야하는 경우에 사용된다.
//스스로해결
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N,i,j,idx, cnt = 0;
    
    scanf("%d",&N);
    
    vector<int> input(N+1);
    
    vector<int> res(N+1);
    
    for(i = 1; i <= N; i++){
        scanf("%d",&input[i]);
    }
    
    idx = N;
    res[1] = idx;
    //어차피 제일 큰 수는 큰수가 없으므로 0임
    //그래서 일단 가장 큰 수부터 넣어놓고 비교 시작함.
    
    for(i = 2; i <= N; i++){
        //tmp = input[idx];
        idx--;
        
        for(j = i-1; j >= 1; j--){
            if(res[j] > idx) cnt++;
            else cnt = 0;
        }
        
       for(j = i-1; j >= 1; j--){
           if(cnt == input[idx]) {
               res[j+1] = idx;
               break;
           }else if (cnt > input[idx]) {
                res[j+1] = res[j];
                cnt--;
               if(cnt == 0){
                   res[j] = idx;
                   break;
               }
           }
        }
        cnt = 0;
    }
    
    for(i = 1; i <= N; i++){
        printf("%d",res[i]);
    }
    
    return 0;
}
