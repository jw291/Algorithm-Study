#include <iostream>
#include <stdio.h>
using namespace std;

//small

int main() {
    int N, tmp ,cnt = 0;
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        tmp = i;
        while(tmp != 0){
            tmp = tmp / 10;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

////large
//int main() {
//    int n, res = 0, d = 9, cnt = 1, sum = 0;
//
//    cin >> n;
//
//    while(d+sum < n){
//        res = res + (cnt * d);
//        sum = sum + d;
//        cnt++;
//        d*=10;
//    }
//
//    res = res + ((n-sum)*cnt);
//    cout << res;
//
//    return 0;
//}
