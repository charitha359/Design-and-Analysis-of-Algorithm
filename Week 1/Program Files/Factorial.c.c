#include<stdio.h>
    int fact(int n){
    if(n==0 || n==1){
    return 1;
    }
    else{
    return n*fact(n-1);
    }
}
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    int x;
    x=fact(n);
    printf("The factorial of %d is %d\n:",n,x);
    return 0;
}
