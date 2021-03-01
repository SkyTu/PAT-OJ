# include<stdio.h>


int main(){
    int num[10];
    for(int i=0;i<10;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<10;i++){
        if(num[i]!=0){
            num[i]--;
            printf("%d",i);
            break;
        }
    }
    for(int i=0;i<10;i++){
        while(num[i]-->0)
            printf("%d",i);
    }
}