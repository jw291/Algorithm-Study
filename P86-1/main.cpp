//피자배달거리는 한 집에서의 피자집들까지의 거리중 가장 작은 최소값(가장 가까운 피자집과의 거리)
//도시의 피자배달거리는 각 집에 대한 피자배달거리들을 모두 합한 값(A-피자집1 + B-피자집2+....+)

//이 문제가 원하는 것은 피자배달거리를 구할 때, 6개의 피자집과의 거리를 모두 비교하는 것이 아니라
//4개만 뽑아서 비교할 것이다.
//4개중 하나는 집A와 가장 가까운 피자집일 수 있고 4개중 다른 하나는 집B와 가장 가까운 피자집일 수 있다.
//이렇게 서로다른 6개의 피자집 중, 4개를 뽑을 수 있는 모든 경우의 수에 대한 도시의 피자배달거리를 구해보고
//가장 최소값이 가장 최선의 피자집4개가 될 것이다.
//최소값을 구하라.

//코드는 거의 스스로 짯는데 마지막까지 도달을 못했네...
//일단 pz[ch[j]]이거 실수했음
//dis = 2147000000이거 위치 애매했음
//min함수 이용하는거 매우 유용함
//if(sum<res) res = sum이거 생각 못했음.
//min값을 작은 틀에서 한번 큰틀에서 한번 더 뽑다보니까 좀 햇깔렸는데
//결과적으로 흐름은 잘 짯음
//실수만 덜하면 될듯.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,dis,sum=0,res = 2147000000;
int ch[13];
vector<pair<int, int>> hs,pz;
vector<int> result;

void DFS(int s, int L){
    if(L == M){//nCm 서로다른 n개중 선택된 m개가 만들어짐.
        sum = 0;
        for(int i = 0; i < hs.size(); i++){
            dis = 2147000000;//min함수를 사용하는 방법.
            for(int j = 0; j < L; j++){
                dis = min(dis,abs(hs[i].first-pz[ch[j]].first)+abs(hs[i].second-pz[ch[j]].second));
                
            }
            sum = sum + dis;
        }
        if(sum<res) res = sum;
    }
    else{
        for(int i = s; i <= pz.size(); i++){
            ch[L] = i;//해당 레벨에서 선택된 값.
            DFS(i+1,L+1);
        }
    }
}

int main() {
    int tmp,i,j;
    
    scanf("%d %d",&N, &M);
    
    int map[N+1][N+1];
    
    
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            scanf("%d",&tmp);
            map[i][j] = tmp;
            if(tmp == 1) hs.push_back(make_pair(i, j));
            else if(tmp == 2) pz.push_back(make_pair(i, j));
        }
    }
    DFS(0,0);
    printf("%d",res);
    
    
    return 0;
}
/*
4 4
0 1 2 0
1 0 2 1
0 2 1 2
2 0 1 2
*/
