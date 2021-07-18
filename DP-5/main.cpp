//다른 아이디어로 풀었는데
//오른쪽 배열의 최대부분 증가수열을 구하는 문제임
//오름차순, 숫자, 최대~ : 최대길이증가수열 문제

#include <iostream>
#include <algorithm>

using namespace std;

int R_arr[101];
int dy[101];
int main() {
    ios_base::sync_with_stdio(false);

    int N, res = 0;
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> R_arr[i];
    }

    dy[1] = 1;

    for(int i = 2; i <= N; i++){
        int max = 0;
        for(int j = i-1; j >= 1; j--){
            if(R_arr[i] > R_arr[j] && dy[j] > max)
                max = dy[j];
        }
        dy[i] = max+1;
        if(dy[i] > res) res = dy[i];
    }

    cout << res;
}
//아래처럼 풀면 틀림
//최대부분 증가 수열로 해결하는 방법이 아님
//더 많이 그을 수 있는데 그걸 고려하지 않고
//일단 자기와 같은것을 그어버리기 때문에
//최대 값을 얻을 수 없음
//int L_arr[101];
//int R_arr[101];
//int main() {
//    ios_base::sync_with_stdio(false);
//
//    int N, sum = 0;
//    cin >> N;
//
//    for(int i = 1; i <= N; i++){
//        L_arr[i] = i;
//        cin >> R_arr[i];
//    }
//
//    int s = 1;
//
//    for(int i = 1; i <= N; i++){
//        for(int j = s; j <= N; j++){
//            if(L_arr[i] == R_arr[j]){
//                sum = sum+1;
//                s = j+1;
//                continue;
//            }
//        }
//    }
//
//    cout << sum << "!";
//    return 0;
//}
