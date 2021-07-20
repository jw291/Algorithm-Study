//bfs로도 가능함

#include <iostream>
#include <queue>

using namespace std;

int map[21][21];
int dy[21][21];
int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }
    
    //어차피 오른쪽과 아래쪽으로 가는게 최단거리임
    //따라서 출발점으로 오른쪽으로 쭉
    //출발점으로 아래쪽으로 쭉 누적값을 더해놓아도 됌(문제를 통해 직관적으로 알 수 있는 부분)
    //그 다음에 위쪽 값과 왼쪽값을 비교해서 더 작은 값을 현재 자신과 더해주면 최단거리가 됌
    dy[1][1] = map[1][1];
    for(int i = 2; i <= N; i++){
        dy[1][i] = dy[1][i-1] + map[1][i];
        dy[i][1] = dy[i-1][1] + map[i][1];
    }
    
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= N; j++){
            dy[i][j] = min(dy[i-1][j],dy[i][j-1]) + map[i][j];
//            if(dy[i-1][j] < dy[i][j-1]) dy[i][j] = dy[i-1][j] + map[i][j];
//            else  dy[i][j] = dy[i][j-1] + map[i][j];
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << dy[i][j]<<" ";
        }
        cout << endl;
    }
    
}
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int map[21][21];
//int dy[21][21];
//
//int row[2] = {1,0};
//int col[2] = {0,1};
//int main() {
//    ios_base::sync_with_stdio(false);
//    int N;
//    queue<pair<int,int>> q;
//    cin >> N;
//
//    for(int i = 1; i <= N; i++){
//        for(int j = 1; j <= N; j++){
//            cin >> map[i][j];
//            if(i == 1 && j == 1){
//                dy[i][j] = map[i][j];
//            }else{
//                dy[i][j] = 2147000000;
//            }
//        }
//    }
//
//    q.push(make_pair(1,1));
//
//    while(!q.empty()){
//        pair<int, int> x = q.front();
//        q.pop();
//
//        for(int i = 0; i < 2; i++){
//            int _x = x.first + row[i];
//            int _y = x.second + col[i];
//            int energy = dy[x.first][x.second] + map[_x][_y];
//            if(energy < dy[_x][_y]) {
//                dy[_x][_y] = energy;
//                q.push(make_pair(_x, _y));
//            }
//        }
//    }
//
//    cout << dy[N][N];
//
//    return 0;
//}
/*
5
3 7 2 1 9
5 8 3 9 2
5 3 1 2 3
5 4 3 2 1
1 7 5 2 4
 */
