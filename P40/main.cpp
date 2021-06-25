#include <iostream>
#include <vector>
#include <algorithm> //sort 퀵정렬
//앞에 배운 병합을 응용한
//정렬하고 두개의 포인터로 비교하는 방식
//정렬하는 이유는 비교하는 두 포인터의 값중 하나가 작으면
//작은 포인터를 하나씩 증가시키기 위해서
//앞뒤 안보고 증가시켜도 된다. 어차피 값이 작기 때문에
//투포인터 알고리즘
using namespace std;
int main() {
    int n, m, i, p1=0,p2=0,p3=0;
    
    scanf("%d",&n);
    vector<int> a(n+1);
    
    for (i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    
    sort(a.begin(), a.end());//퀵정렬
    
    scanf("%d",&m);
    vector<int> b(m+1);
    for (i = 1; i <= m; i++) {
        scanf("%d",&b[i]);
    }
    
    sort(b.begin(), b.end());
    
    vector<int> c(n+m);
    while (p1 <= n && p2 <= m) {
        if(a[p1] == b[p2]) {
            c[p3++] = a[p1];
            p1++;
            p2++;
        }
        else if(a[p1] < b[p2]) p1++;
        else p2++;
    }
    
    for (i = 1; i < p3; i++) {
        printf("%d",c[i]);
    }
    
    return 0;
}
