#include <stdio.h>
#include <vector>

using namespace std;
int main() {
    int N, M, i;
    
    int lt,rt,mid;
    
    scanf("%d %d",&N, &M);
    vector<int> vec(N);
    //vector<int> vec;
    
    for(i = 0; i < N; i++){
        scanf("%d", &vec[i]);
        //scanf("%d", tmp);
        //vec.push_back(tmp);
    }
    
    sort(vec.begin(), vec.end());
    
    lt = 0;
    rt = N-1;
    while(lt <= rt){
        mid = (lt+rt)/2;
        if(vec[mid] == M){
            //정답
            printf("%d",mid+1);
            break;
        }
        else if(vec[mid] < M){
            //key는 오른쪽에 있으므로 오른쪽으로 검색 범위 축소
            lt = mid+1;
        }else if(vec[mid] > M){
            //key는 왼쪽에 있으므로 왼쪽으로 검색 범위 축소
            rt = mid-1;
            
        }
    }
    return 0;
}
