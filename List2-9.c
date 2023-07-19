/*用字幕显示名字（其一：从右往左滚动字符）*/
#include<stdio.h>
#include<string.h>
#include<time.h>
int sleep(unsigned long x){
    clock_t c1=clock(),c2;

    do{
        if((c2=clock())==(clock_t)-1)
        return 0;
    }while(1000.0*(c2-c1)/CLOCKS_PER_SEC<x);
    return 1;
}
int main(void){
    int i;
    int cnt=0;
    char name[]="Kangjinmeng ";
    int name_len=strlen(name);

    while(1){

        putchar('\r');

        for(i=0;i<name_len;i++){
            if(cnt+i<name_len)
            putchar(name[cnt+i]);
            else 
            putchar(name[cnt+i-name_len]);
        }
        fflush(stdout);
        sleep(500);

        if(cnt<name_len-1)
        cnt++;
        else
        cnt=0;
    }

    return 0;
}