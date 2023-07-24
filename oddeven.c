#include<stdio.h>
#include<unistd.h>

int main(){
    int fd[2];
    int fd1[2];
    int num;
    int arr[50];
    
    if(pipe(fd)==-1||pipe(fd1)==-1){
        printf("error in creating pipe");
    }
    else{
        printf("pipe connection successful");
    }
    
    int pid=fork();
    if(pid<0)
    printf("error creating fork");
    if(pid==0){
        printf("child process\n");
        close(fd[0]);
        close(fd1[0]);
        printf("enter the numb of elements you want to send from child to parent:\n");
        scanf("%d",&num);
        printf("enter the numbers:");
        for(int i=0;i<num;i++){
            scanf("%d",&arr[i]);
        }
        write(fd1[1],&num,sizeof(int));
        write(fd[1],&arr,num*sizeof(int));
    }
    else{
        printf("parent process:\n");
        close(fd[1]);
        close(fd1[1]);
        read(fd1[0],&num,sizeof(int));
        read(fd[0],&arr,num*sizeof(int));
        printf("even numbers received from child:");
        for(int i=0;i<num;i++){
            if(arr[i]%2==0){
                printf("%d\t",arr[i]);
            }
        }
        printf("odd numbers received from child:");
        for(int i=0;i<num;i++){
            if(arr[i]%2!=0){
                printf("%d\t",arr[i]);
            }
        }
    }
}
