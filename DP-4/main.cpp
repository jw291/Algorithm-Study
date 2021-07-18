//다이나믹 테이블에는 정답이 들어가야햠.
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dy[1001];
int main() {
    ios_base::sync_with_stdio(false);
    int N,num,res = 0;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    
    dy[1] = 1;
    
    for(int i = 2; i <= N; i++){
        int max = 0; //0으로 해놓으면 아주 편함. 자기보다 작은 arr값이 없을때 else로 dy[i] = 1할 필요 없음
        for(int j = i-1; j >= 1; j--){
            if(arr[j]<arr[i] && dy[j] > max)
                max = dy[j];
        }
        dy[i] = max + 1; //max는 0으로 초기화 돼있기 때문에 max값이 바뀌지 않으면 걍 1이 들어감
        if(dy[i]>res) res = dy[i];
    }
        
    
//    for(int i = 2; i <= N; i++){
//        int len = -2147000000;
//        for(int j = i-1; j >= 1; j--){
//            if(arr[j] < arr[i]){
//                num = dy[j];
//                len = max(len, num);
//                dy[i] = len+1;
//            }else{
//                dy[i] = 1;
//            }
//        }
//    }
//
//    for(int i = 1; dy[i] != '\0'; i++){
//        if(dy[i] > res){
//            res = dy[i];
//        }
//    }
//
    cout << res;
    return 0;
}
