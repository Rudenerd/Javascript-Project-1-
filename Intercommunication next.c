#include<stdio.h>
#include<unistd.h>
int main(){
  int fd[2],n;
  pid_t p;
  char buffer[100];
  pipe(fd);

  p=fork();
  if(p>0){
    printf("Passing data to child\n");
    write(fd[1],"hello\n",6);
  }
  else{
    printf("Child Received data\n");
    n=read(fd[0],buffer,100);
    write(1,buffer,n);
  }
}