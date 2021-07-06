//여러개의 값을 비교해야 하는 경우
//struct vector operation
//날짜를 정렬하고
//머니는 최대힙에
//어차피 머니를 더하는게 중요하니까

//한 쌍의 값 중 날짜로만 정렬해야함
//날짜로 정렬하면 3,2,1로 정렬돼서
//문제 없음.(생각해보면 됌)
//만약 모든 날짜가 다 1이면
//하나밖에 선택을 못함(다 하루안에 와야하니까)
//흠.. 이것끼지 대비가 되려나

//코드 돌려보기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Loc{
    int money;
    int date;
    
public:
    Loc(int money, int date){
        this->money = money;
        this->date = date;
    }
    
    bool operator<(const Loc &ref)const{
        return date>ref.date;
    }
};

int main() {
    int N,M,D,i,datemax=-2147000000,sum=0;
    priority_queue<int> pQ;
    vector<Loc> vec;
    
    scanf("%d",&N);
    
    for(i=0; i<N; i++){
        scanf("%d %d",&M,&D);
        //일단 날짜부터 정렬해야함
        //한 쌍을 입력하고 그 중 하나의 값만 정렬해야함.
        //pairs.second가 생각남.
        //하지만 구조체를 이용하자.
        //vector에 구조체 객체를 넣고 sort해서 operator동작시키는 방식
        vec.push_back(Loc(M,D));
        if(D > datemax) datemax = D;
    }
    sort(vec.begin(), vec.end());//날짜로 정렬 완료
    
    //이제 하나하나씩 heap에 넣음
    //날짜는 정렬이 됐으니 이제 money를 힙에 넣어주면 됌.
    //마지막 날에는 날짜가 3인 값만 들어올 수 있음
    //두번째 날에는 날짜가 3,2인 값만 들어올 수 있음
    //첫번째 날에는 날짜가 3,2,1인 값만 들어올 수 있음
    //힙에 날짜가 3인값을 다 넣은 다음 최대힙을 더함(3중에 큰 값)
    //그다음 날짜가 2인값을 다 넣은 다음 최대힙을 더함(자연스럽게 날짜가 3인 남은 값 하나랑 날짜가2인 값들 끼리 비교해서 최대힙 구해지겠지)
    //그다음 날짜가 1인값을 다 넣은 다음 최대힙을 더합(날짜가 3인 남은값 날짜가 2인 남은 값 날짜가1인 값들끼리 비교해서 최대힙 구해지겠지)
    while(datemax != 0){
        
        for(auto pos : vec){
            if(pos.date == datemax){
                //printf("%d",pos.money);
                pQ.push(pos.money);
            }
        }
        sum += pQ.top();
        pQ.pop();
        
        datemax--;
    }
    
    printf("%d",sum);
    return 0;
}
/*
6
50 2
20 1
40 2
60 3
30 3
30 1
 */
