//j시간에 얻을 수 있는 최대점수 dy[j]
//dy[j-t]+s t만큼의 시간을 써서 s만큼의 점수를 얻는다.
//dy[j-t]는 j-t만큼의 시간에 얻을 수 있는 최대 점수가 들어가 있을 것이다.
//그 예시로 dy[3]에는 6이 들어갈 것이다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int N, M , t, s;
    cin >> N >> M;
    vector<int> dy(M+1,0);
    
    for(int i = 0; i < N; i++){
        cin >> s >> t;
        for(int j = t; j <=M; j++){
            dy[j] = max(dy[j], dy[j-t]+s);
            //cout << dy[j] << " ";
        }
        //cout << endl;
    }
    
    cout << dy[M];
    return 0;
}
