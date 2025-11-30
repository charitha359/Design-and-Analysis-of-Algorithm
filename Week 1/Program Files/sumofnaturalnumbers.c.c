#include<stdio.h>
    int sumOfNaturalNumbers(int n){
    int i,sum=0;
    for(i=1;i<=n;i++){
    sum+=i;
    }
    return sum;
}
int main(){
    int n;
    printf("Enter the no.of natural numbers:");
    scanf("%d",&n);
    int z;
    z=sumOfNaturalNumbers(n);
    printf("%d\n",z);
    return 0;
}




