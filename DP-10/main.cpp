//dy[j-c]+1
//j만큼 거슬러준다고 했을 때
//j-c는 c동전을 이미 거슬러 준거임 +1은 개수 하나 추가한 것
//dy[j-c]값은 c동전을 거슬러주었다고 가정했을 때 최선의 개수가 이미 담겨있었겠지
//거기에 c동전 하나 즉, +1을 해준거
//최선의 개수 +1이 된 거임.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int N,M;
    
    cin >> N;
    vector<int> coin(N);
    for(int i = 0; i < N; i++){
        cin >> coin[i];
    }
    
    cin >> M;
    
    vector<int> dy(M+1,1000);
    dy[0] = 0;//직관적 가능 이걸 무조건 해줘야함
    //아니면 0에 계속 1000이 담겨서 값이 안나옴
    
    for(int i = 0; i < N; i++){
        int c = coin[i];
        for(int j = c; j <= M; j++){
            dy[j] = min(dy[j], dy[j-c]+1);
        }
    }
    
    cout << dy[M];
    return 0;
}
