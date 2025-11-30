#include<stdio.h>
int main(){
    int n;
    printf("Enter the  value:");
    scanf("%d",&n);
    int i,sum=0;
    for(i=1;i<=n;i++){
    sum+=i*i*i;
    }
    
  
    printf("%d\n",sum);
    return 0;
}
