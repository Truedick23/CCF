#include<stdio.h>
#include<math.h>
#define MAX 1000
int WEISHU(int num){
    int s = 1;
    while(num/10 != 0){
        s++;
        num = num/10;
    }
   return s;i
}
int main(){
    int n,i,x,num[i],num1;
    scanf("%d",&n);
    x = WEISHU(n);
    for(i = 1 ; i <= x; i++){
        num1 = (int)pow((double)10,(double)n);
        num[i] = n % num1;
        printf("%d\n", num[i]);
    }
    return 0;
}
