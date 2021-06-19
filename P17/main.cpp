#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int N, j, i, num, ans, sum = 0;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> num >> ans;
        sum = 0;
        for(j = 1; j <= num; j++){
            sum += j;
        }
        if(sum == ans) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
