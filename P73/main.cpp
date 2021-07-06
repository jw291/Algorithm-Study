//우선순위 큐는 max heap구조임
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//최소힙 -붙이는 아이디어
int main() {
    int a;
    priority_queue<int> pQ; //알아서 맥스힙 구조로 바뀌나봄
    
    while(true) {
        scanf("%d",&a);
        if(a==-1) break;
        
        if(a==0){
            if(pQ.empty()) printf("-1\n");
            else{
                printf("%d\n",-pQ.top());//원상태 복구
                pQ.pop();
            }
        }else pQ.push(-a); //-넣어서 min heap
    }
    return 0;
}
//최대힙
//int main() {
//    int a;
//    priority_queue<int> pQ; //알아서 맥스힙 구조로 바뀌나봄
//
//    while(true) {
//        scanf("%d",&a);
//        if(a==-1) break;
//
//        if(a==0){
//            if(pQ.empty()) printf("-1\n");
//            else{
//                printf("%d\n",pQ.top());//루트값
//                pQ.pop();
//            }
//        }else pQ.push(a);
//    }
//    return 0;
//}
