#include <iostream>
#include <map>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    map<char,int> A,B;
    map<char,int>::iterator it;
    char input1[101];
    char input2[101];
    int input1_len = 0;
    int input2_len = 0;
    bool flag = true;
    
    cin >> input1;
    for(int i = 0; input1[i] != '\0'; i++){
        A[input1[i]]++;
        input1_len++;
    }
    
    cin >> input2;
    for(int i = 0; input2[i] != '\0'; i++){
        B[input2[i]]++;
        input2_len++;
    }
    
    if(input1_len != input2_len){ //크기가 다르면 무조건 다르니까 그냥 끝내버리기
        cout << "NO" << endl;
        exit(0);
    }
    
    for (it = A.begin(); it != A.end(); it++) {
        if(B[it->first] != it->second){
            flag = false;
        }
    }
    
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    
    
}
//#include <stdio.h>
//#include <algorithm>
//char A[60],B[60];
//int main() {
//    char str[100];
//    int i;
//
//    scanf("%s",&str);
//    for(int i = 0; A[i] != '\0'; i++){
//        if(str[i] >= 65 && str[i] <= 90){//소문자
//            A[str[i] - 64]++; //해당 index에 count한다.
//        }
//        else if(str[i] >= 97 && str[i] <= 122){
//            A[str[i] - 70]++; //해당 index에 count한다.
//        }
//    }
//
//    scanf("%s",&str);
//    for(int i = 0; B[i] != '\0'; i++){
//        if(str[i] >= 65 && str[i] <= 90){//소문자
//            B[str[i] - 64]++; //해당 index에 count한다.
//        }
//        else if(str[i] >= 97 && str[i] <= 122){
//            B[str[i] - 70]++; //해당 index에 count한다.
//        }
//    }
//
//    for(i =0; i<= 52; i++){
//        if(A[i] != B[i]){
//            printf("NO\n");
//            exit(0);
//        }
//    }
//    printf("Yes\n");
//    return 0;
//}
