#include <iostream>

using namespace std;
int main() {
    int i, digit, max = -2147000000, res;
    int cnt[10];
    int n[101];
    
    scanf("%s",&n);
    
    for(i = 0; i <= '\0'; i++){
        digit = n[i]-48;
        cnt[digit]++;
    }
    
    for(i = 0; i <= 9; i++){
        if(cnt[i] >= max){
            max = cnt[i];
            res = i;
        }
    }
    
    return 0;
}
