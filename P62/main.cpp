//재귀는 무조건
//dfs그리듯이
//d(1,2)이런식으로 트리를 만들어야함
//그래야 본인이 해야할일에 대해서 직관적으로 생각할 수 있음

//자기 일 하고 왼쪽자식과 오른쪽자식을 생성해야지
//왼쪽자식과 오른쪽자식 끝났으니까 자기 일 해야지
#include <iostream>
int data[10], tmp[10];

void divide(int lt, int rt){
    int mid;
    int p1, p2, p3;
    if(lt < rt)
    {
        mid = (lt+rt)/2;
        divide(lt, mid);
        divide(mid+1,rt);
        //여기까지 분할 기본 뼈대
        //싹다 분할 완료함
        
        //이제 합치면서 정렬
        //진짜 합친다는게 아니라 다른 배열에 정렬시킨거 넣었다가 복사
        //if에 걸려서 더이상 자식을 생성할 수 없는
        //본인의 해야할일을 이제 해야함
        p1 = lt;
        p2 = mid+1;
        p3 = lt;
        while(p1 <= mid && p2 <= rt){
            if(data[p1] < data[p2]) tmp [p3++] = data[p1++];
            else tmp [p3++] = data[p2++];
        }
        
        //나머지 쓸어담기
        while(p1 <= mid) tmp[p3++] = data[p1++];
        while(p2 <= rt) tmp[p3++] = data[p2++];
        
        //원데이터 바꾸기
        for(int i = lt; i <= rt; i++){
            data[i] = tmp[i];
        }
        
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &data[i]);
    }
    
    //lt rt넘기기 == 정렬 범위
    divide(1,n);
    for(i = 1; i <= n; i++){
        printf("%d ", data[i]);
    }
    return 0;
}
