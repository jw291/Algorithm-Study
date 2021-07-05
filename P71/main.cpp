//인접리스트를 이용했는데 굳이 인접리스트를 쓸 필요가 없다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 10001

using namespace std;

int main() { // 인접 리스트 안쓰고 푸는 방법임
    int S,E;
    
    queue<int> Q;
    
    scanf("%d %d",&S,&E);
    
    int dx[3] = {-1, 1, 5};//여러모로 굉장히 유용함
    
    int ch[MAX] ={0}; //distance를 가짐
    int x,i;
    int pos;
    
    
    ch[S] = 1;
    Q.push(S);
    
    while (!Q.empty()) {
        x = Q.front();
        Q.pop();
        for(i = 0; i < 3; i++){
            pos = x + dx[i];
            if(pos <= 0 || pos > 10000) continue;
            if(pos == E){
                printf("%d\n", ch[x]);
                exit(0);
            }
            if(ch[pos] == 0){
                ch[pos] = ch[x]+1;
                Q.push(pos);
            }
        }
    }
    
    return 0;
}

//int main() {
//    int S,E,v1,v,v2;
//
//    queue<int> Q;
//
//    scanf("%d %d",&S,&E);
//
//    int ch[MAX] ={0};
//    int dis[MAX] = {0};
//    int x,i;
//    vector<int> map[1000];
//
//    for(i = 1; i <= E; i++){
//        map[i].push_back(i-1);
//        map[i].push_back(i+1);
//        map[i].push_back(i+5);
//    }
//
//    ch[S] = 1;
//    Q.push(S);
//
//    while (!Q.empty() && ch[E] == 0) {
//        x = Q.front();
//        Q.pop();
//        for(i = 0; i < map[x].size(); i++){
//            if(ch[map[x][i]] == 0){
//                ch[map[x][i]] = 1;
//                Q.push(map[x][i]);
//                dis[map[x][i]] = dis[x] + 1;
//            }
//        }
//    }
//
//    printf("%d\n",dis[E]);
//
//    return 0;
//}
