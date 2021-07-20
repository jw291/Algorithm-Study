//top down
//스스로 해결
#include <iostream>
#include <queue>

using namespace std;

int map[21][21];
int dy[21][21];


//난 일단 쭉 뻗어나가고 값을 구하면서 위로 올라가야된다고 생각했음
//그래서 if안에서는 곧바로 dy에 넣어주지 않았음.

//하지만 트리 그려보면 이 코드가 더 깔끔하다는 걸 알 수 있음
//어쨋든 틀린건 아니니까 스스로 해결
int D(int row, int col){
    if(dy[row][col] > 0) return dy[row][col];
    if(row == 1 && col == 1) return dy[row][col] = map[row][col];
    else{
        if(col == 1) return dy[row][col] = D(row,col-1)+map[row][col];
        else if(row == 1) return dy[row][col] = D(row-1,col)+map[row][col];
        else return dy[row][col] = min(D(row-1,col),D(row,col-1)) + map[row][col];
    }
}

//int D(int row, int col){
//    int top = 2147000000;
//    int left = 2147000000;
//
//    if(dy[row][col] > 0) return dy[row][col]; //메모이제이션
//
//    if(row == 1 && col == 1) return dy[row][col] = map[row][col];
//    else{
//        if (row > 1 && col > 1){
//            top = D(row-1,col)+map[row][col];
//            left = D(row,col-1)+map[row][col];
//        }
//        else if (row > 1 && col == 1){
//            top = D(row-1,col)+map[row][col];
//        }
//        else if (row == 1 && col > 1){
//            left = D(row,col-1)+map[row][col];
//        }
//    }
//    return dy[row][col] = min(top,left);
//}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }
    
    cout << D(N,N) << endl;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << dy[i][j]<< " ";
        }
        cout <<endl;
    }
}
/*
5
3 7 2 1 9
5 8 3 9 2
5 3 1 2 3
5 4 3 2 1
1 7 5 2 4
 */
