//마치 네트워크처럼 모든 친구들간의 관계를 말하고 있으며
//서로 친구가 아닐 수도 있는 경우를 말하고 있다
//플로이드 와샬

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N,a,b;
    cin >> N;
    vector<int> res(N+1,0);
    vector<vector<int>> dy(N*N-1,vector<int>(N*N-1,5000));
    
    while(1){
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        else{
            dy[a][b] = 1;
            dy[b][a] = 1; //친구니까 양방향임 햇깔리지마
        }
    }
    
    for(int i = 1; i <= N; i++) dy[i][i] = 0;
    
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                dy[i][j] = min(dy[i][j], dy[i][k]+dy[k][j]);
            }
        }
    }
    
    int score = 100;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            res[i] = max(res[i],dy[i][j]);
        }
        score = min(score, res[i]);
    }
    
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        if(res[i] == score) cnt++;
    }
    
    cout << score << " " << cnt << endl;
    
    for(int i = 1; i <= N; i++){
        if(res[i] == score) cout << i << " ";
    }
    
}
/*
5
1 2
2 3
3 4
4 5
2 4
5 3
 -1 -1

 
 */
