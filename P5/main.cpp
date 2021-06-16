#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    char addr[20];
    int year, age;
    char gender;
    
    scanf("%s",&addr);
    
    cout << 1900 + ((addr[0]-48)*10) + (addr[1]-48) << endl;
    
    if(addr[7] == '1' || addr[8] == '2') year = 1900 + ((addr[0]-48)*10) + (addr[1]-48);
    else year = 2000 + ((addr[0]-48)*10) + (addr[1]-48);
        
    if(addr[7] == '1' || addr[7] == '3') gender = 'M';
    else gender = 'W';
    
    age = 2019 - year + 1;
    printf("%d", age);
    printf("%c", gender);
    return 0;
}
