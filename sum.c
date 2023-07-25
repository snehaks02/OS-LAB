#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
    int fd1[2];
    int fd[2];
    int sizeparent;
    int arrayparent[sizeparent];
    
    if(pipe(fd1)==-1||pipe(fd)==-1)
    printf("error creating pipe");
    int pid=fork();
    if(pid<0)
    printf("error creataing fork");
    if(pid==0){
        close(fd[1]);
        close(fd1[1]);
        printf("child process\n");
        read(fd[0],&sizeparent,sizeof(int));
        read(fd1[0],arrayparent,sizeof(arrayparent));
        int sum=0;
        for(int i=0;i<sizeparent;i++){
            sum+=arrayparent[i];
        }
        printf("sum :%d",sum);
    }
    else{
        close(fd1[0]);
        close(fd[0]);
        printf("parent process\n");
        printf("enter the size of array:");
        int sizechild;
        scanf("%d",&sizechild);
        printf("enter the array elements");
        int arryc[sizechild];
        for(int i=0;i<sizechild;i++){
            scanf("%d",&arryc[i]);
        }
        write(fd[1],&sizechild,sizeof(int));
        write(fd1[1],arryc,sizeof(arryc));
    }
}
