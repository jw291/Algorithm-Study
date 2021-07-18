//가장 높은 탑(최대),숫자,오름차순을 내포하고 있으므로 최대부분증가수열
//순서대로 1부터연속적 인 번호 이게 최대부분증가수열을 나타내는 핵심이기도 함
//입력 순서를 무조건 지켜야함
//입력 순서를 벗어나며 다른 답이 나옴 (최대부분 증가수열도 입력 순서르 다르게 하면 답이 다르듯이)
//스스로 풀었음 돌려보자
#include <iostream>
#include <vector>

using namespace std;

int dy[101];

struct Stone{
    int width;
    int height;
    int weight;
    
    Stone(int wid, int hei, int wei){
        width = wid;
        height = hei;
        weight = wei;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    
    int N, wi,he,we,max;
    vector<Stone> vec;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> wi >> he >> we;
        vec.push_back(Stone(wi,he,we));
    }
    
    dy[0] = vec[0].height; // 입력 순서를 절대적으로 따르므로
    //탑을 하나 쌓았다면 무조건 첫번째 값은 첫번째로 입력된 벽돌의 높이이다.
    
    for(int i = 1; i < N; i++){
        max = 0;
        dy[i] = vec[i].height;
        
        for(int j = i-1; j >= 0; j--){
            if(( vec[j].width > vec[i].width)&&(vec[j].weight >= vec[i].weight)){
                if(dy[j] > max){
                    max = dy[j];
                }
            }
        }
        dy[i] = dy[i] + max;
    }
    
    for(int i = 0; i < N; i++)
        cout << dy[i]<<endl;
    
    cout << dy[N-1];
    return 0;
}
/*
5
25 3 4
4 4 6
9 2 3
16 2 5
1 5 2
 */
