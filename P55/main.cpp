//결과가 순서대로라고 한다면
//반복문의 index를 이용하는 것이 가장 좋음
//결과와 반복문의 index가 같으므로
//결과값을 이용할 수가 있음.
//결과값을 이용하면 좀 더 명확한 답을 도출해낼 수 있음

//채점해보기
//굳이 P,O를 벡터에 넣어서 출력해야되나
//아, 벡터에 넣어놓고 안하면 P,O를 출력하고 impossible을 함.
//이건 걍 해보면 아는거네

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N,i,j=1;
    scanf("%d",&N);
    int a;
    stack<int> st;
    vector<char> str(N);
    
    for(i = 1; i <= N; i++){
        scanf("%d",&a);
        st.push(a);
        str.push_back('P');
        
        while(1){
            if(st.empty()) break;
            if(st.top() == j){
                st.pop();
                str.push_back('O');
                j++;
            }else break;
        }
    }
    
    if(!st.empty()) printf("impossible\n");
    else {
        for(i = 1; i <= str.size(); i++){
            printf("%c",str[i]);
        }
    }
    /*
    for(i = 0; i < N; i++){
        scanf("%d",&a[i]);
        
        if(st.empty()){
            if(i == N-1){
                st.push(a[i]);
                printf("P");
                st.pop();
                printf("O");
            }else{
                st.push(a[i]);
                printf("P");
            }
        }else{
            if(a[i] > st.top()){
                st.pop();
                printf("O");
                if(st.empty()){
                    st.push(a[i]);
                    printf("P");
                    st.pop();
                    printf("O");
                }
            }else if(a[i] < st.top()){
                st.push(a[i]);
                printf("P");
                st.pop();
                printf("O");
            }
        }
    }*/
    
    return 0;
}
