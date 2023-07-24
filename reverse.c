#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
    int fd1[2];
    int fd[2];
    char last,first,temp;
    
    if(pipe(fd1)==-1||pipe(fd)==-1){
        printf("error creating pipe");
    }
    int pid=fork();
    if(pid<0)
    printf("error creating fork");
    if(pid==0){
        close(fd1[0]);
        close(fd[0]);
        char arr1[50];
        int len1;
        printf("\n child");
        printf("\n enter the string:");
        fgets(arr1,sizeof(arr1),stdin);
        len1=strlen(arr1);
        write(fd1[1],&len1,sizeof(int));
        write(fd[1],arr1,sizeof(char)*len1);
    }
    else{
        close(fd1[1]);
        close(fd[1]);
        char arr2[50];
        int len2;
        printf("\n parent process:");
        read(fd1[0],&len2,sizeof(int));
        read(fd[0],arr2,sizeof(char)*len2);
        for(int i=0,j=len2-1;i<j;i++,j--){
            temp=arr2[i];
            arr2[i]=arr2[j];
            arr2[j]=temp;
        }
        for(int i=0;i<len2;i++){
            printf("%c",arr2[i]);
        }
    }
}
