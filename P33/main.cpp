//선택정렬 : 가장 작은 값(key)을 선택하여 교환한다
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int N,tmp,key,cnt = 0;
    
    int arr[100];
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N-1; i++){
        key = i;
        for(int j = key; j < N; j++){
            if(arr[key] > arr[j]) key = j;
        }
        tmp = arr[key];
        arr[key] = arr[i];
        arr[i] = tmp;
    }

    for(int i = 1; i < N; i++){
        if(arr[i-1] != arr[i]) cnt++; //어차피 정렬 돼어있으니까 이전값이랑 중복이 아니면 cnt해준다.
        if(cnt == 3){
            cout << arr[i];
            break;
        }
    }
    return 0;
}
