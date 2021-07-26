#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    map<string,int> ch; //균형잡힌 이진트리로 간다.
    map<string,int>::iterator it;
    //char a[100];
    string a;
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a;
        ch[a]++; //a단어가 키가 되고 1씩 증가
    }
    
    for(it = ch.begin(); it != ch.end(); it++){
        cout << it->first << " " << it->second << "\n";
    }
}
//int main() {
//    ios_base::sync_with_stdio(false);
//    map<char,int> ch; //균형잡힌 이진트리로 간다.
//    map<char,int>::iterator it;
//
//    char a[100];
//    cin >> a;//단어의 각각 알파벳이들어감
//
//    for(int i = 0; a[i] != '\0'; i++){
//        ch[a[i]]++; //a 1 b 1 c 1하다가 또 b면 a 1 b 2 c 1
//    }
//
//    //key값이 오름차순 정렬되어 출력함
//    for(it = ch.begin(); it!=ch.end(); it++){
//        cout << it->first << " " << it->second << "\n"; //first가 key second가 value
//    }
//    return 0;
//}
