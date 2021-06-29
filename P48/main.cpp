//스스로 해결
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int i,j,res,tmp;
    vector<vector<float>> map(9, vector<float>(9));
    float tot = 0;
    float avg[9];
    float max_arr[9];
    int min = 2147000000;
    
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            scanf("%f",&map[i][j]);
            tot += map[i][j];
        }
        avg[i] = round(tot / 9);
        
        tot = 0;
        
    }
    
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            tmp =abs(avg[i]-map[i][j]);
            if(tmp < min){
                min = tmp;
                res = map[i][j];
            }else if(tmp == min){
                if(map[i][j] > res) res = map[i][j];
            }
        }
        printf("%.0f %d\n",avg[i],res);
        min = 2147000000;
    }
    
    
    
    return 0;
}
/*
 3 23 85 34 17 74 25 52 65
10 7 39 42 88 52 14 72 63
87 42 18 78 53 45 18 84 53
34 28 64 85 12 16 75 36 55
21 77 45 35 28 75 90 76 1
25 87 65 15 28 11 37 28 74
65 27 75 41 7 89 78 64 39
47 47 70 45 23 65 3 41 44
87 13 82 38 50 12 48 29 80
 */
