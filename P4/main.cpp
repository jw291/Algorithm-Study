/*
 나이차이
 
 N(2<=N<100)명의 나이가 입력된다. 이 N명의 사람 중 가장 나이차이가 많이 나는 경우는
 몇 살인가? 최대 나이 차이를 출력하는 프로그램을 작성하라
 
 입력
 입력파일은 input.txt로 한다
 첫 줄에 자연수 N(2<=N<=100)이 입력되고, 그 다음 줄에 N개의 나이가 입력된다.
 
 출력
 출력파일은 output.txt로한다
 첫 줄에 최대 나이차이를 출력한다.
 */
#include <iostream>

using namespace std;

int main() {
    //freopen("input,txt", "rt", stdin);
    int N, a, i, max = -2147000000, min = 2147000000;
    
    cin >> N;
    for(i = 1; i<=N; i++){
        cin >> a;
        if(a > max) max = a;
        if(a < min) min = a;
    }
    
    cout << max - min;
    
    return 0;
}
