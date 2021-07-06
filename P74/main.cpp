//vector pair 이용해서 두 값을 한쌍으로해서 사용했는데
//여러개의 값이 한쌍을 이룰 때 어떻게 하는가
//구조체, STL vector을 이용
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Loc{
    int x, y, z;
    
    Loc(int a, int b, int c){
        x = a;
        y = b;
        z = c;
    }
    
    bool operator<(const Loc &ref)const{ //연산자 오버로딩
        if(x!=ref.x) return x<ref.x;
        if(y!=ref.y) return y<ref.y;
        if(z!=ref.z) return z<ref.z;
        //구조체의 주소를 받음
        //call by reference
        //const를 하면 b의 원본을 바꾸지 않음(보안)
        //뒤에다가 const 붙이면 operator가 상수 맴버함수가 된다.
        //그러면 멤버변수 x,y,z값을 변경할 수 없음
        
        //return x<ref.x;
        
        //해당 객체의 x와 피연산되는 객체의 x를 비교
        //즉 객체간의 비교라고 볼 수 있다.
        return 0;
    }
};

int main() {
    vector<Loc> XY;//구조체형 벡터
    XY.push_back(Loc(2,3,5));
    XY.push_back(Loc(3,6,7));
    XY.push_back(Loc(2,3,1));
    XY.push_back(Loc(5,2,3));
    XY.push_back(Loc(3,1,6));//객체가 들어감
    sort(XY.begin(), XY.end());//내부에서 <연산자를 사용하므로 operator<가 동작함
    //만약 +연산자를 사용하면 operator+를 이용해서 자동으로 오퍼레이터가 동작하도록 해야함
    //그니까 객체간의 연산을 하고 싶으면 operator를 이용하면 됌.
    for(auto pos : XY) cout <<pos.x << " "<<pos.y<<" "<<pos.z<<endl;
    //for문으로 vector에 들어간 객체들을 탐색하면서
    //멤버연산자 .을 통해서 Loc객체의 x,y,z를 가리킨다.
    return 0;
}
