#include <iostream>

using namespace std;
int main() {
    //예를들어, 10초동안 체크하는 경보기 = for문 10번 돌린다.
    //연속으로 M이상인 경우 = counting
    
    int N,M,i,num, res,max = -2147000000;
    int cnt;
    //int cnt[100];
    cin >> N >> M;
    
    for(i = 1; i <= N; i++){
        cin >> num;
        if (num > M) cnt++;
        else cnt = 0;
        
        if(cnt > max) max = cnt; // 바로 max에 넣으면 되는거였네..
    }
    
    if(max == 0) cout << -1 << "\n";
    else cout << max;
    /*
    cnt[0] = 0;
    
    for(i = 1; i <= N; i++){
        cin >> num;
        if(num > M){
            cnt[i] = cnt[i-1] + 1;
        }else {
            cnt[i] = 0;
        }
    }
    
    for(i = 1; i <= N; i++){
        if(cnt[i] > max){
            max = cnt[i];
        }
    }
    
    cout << max;
     */
    return 0;
}
