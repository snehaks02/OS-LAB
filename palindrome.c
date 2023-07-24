#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<stdbool.h>

bool isPalindrome(const char *str){
    int len=strlen(str);
    int i,j;
    for(i=0,j=len-1;i<j;i++,j--){
        if(str[i]!=str[j]){
            return false;
        }
        
    }
    return true;
}

int main(){
    int fd[2];
    int fd1[2];
    pipe(fd);
    
    if(pipe(fd)==-1 || pipe(fd1)==-1){
        printf("error creating in pipe");
    }
    
    int pid=fork();
    if(pid<0){
        printf("error in creating the fork");
    }
    if(pid==0){
        close(fd[0]);
        close(fd1[0]);
        char arr1[50];
        int len1;
        printf("child process:\n");
        printf("enter the string:\n");
        fgets(arr1,sizeof(arr1),stdin);
        len1=strlen(arr1);
        write(fd1[1],&len1,sizeof(int));
        write(fd[1],arr1,sizeof(char)*len1);
    }
    else{
        close(fd[1]);
        close(fd1[1]);
        char arr2[50];
        int len2;
        printf("\n parent process:");
        read(fd1[0],&len2,sizeof(int));
        read(fd[0],arr2,sizeof(char)*len2);
        arr2[len2-1]='\0';
        if(isPalindrome(arr2)){
            printf("palindrome");
        }
        else{
            printf("not palindrome");
            close(fd[0]);
            
        }
        
    }
}

