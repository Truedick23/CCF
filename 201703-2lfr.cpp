#include<stdio.h>
#include<iostream>

using namespace std;
int a[1000],b[1000];
int main()
{
    int n,m,p,q,i,j, pos = 0, fron, tail;      //n为学生的数量，m为调整的次数
    scanf("%d %d", &n, &m);

    for(i = 1 ; i <= n ; i++)
        a[i] = i;
    for(i = 0; i < m ; i++){
         scanf("%d %d", &p, &q);
         int x = a[p];
         for(int i = 1; i <= n; i++)
            if(a[i] == p)
                pos = i;
         if(q > 0) {
            fron = pos;
            tail = fron + q;
            int temp = a[fron];
            for(int j = fron; j < tail; j++)
                a[j] = a[j + 1];
            a[tail] = temp;
         }
        else {
            tail = pos;
            fron = tail + q;
            int temp = a[tail];
            for(int j = tail; j > fron; j--)
                a[j] = a[j - 1];
            a[fron] = temp;
        }
    }
    for(i = 1; i <= n; i++)
        print("%d ", a[i]);
    return 0;
}
