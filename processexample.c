#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void childProcess(){

  for(int x = 0; x< 10; ++x){
    printf("child process %d\n",x );
    sleep(1);

  }

  _exit(0);

}


void parentProcess(){

  for(int y = 0; y< 10; ++y){
    printf("Parent  process %d\n",y);
    sleep(2);

  }

  _exit(0);

}

int main(int argc, char*argv[]){


  pid_t pid;

  pid = fork();

  if(pid == -1){

    fprintf(stderr, " cant fork , error %d\n", errno );
    exit(EXIT_FAILURE);

  }

  if(pid == 0){

    childProcess();

  } else{

    parentProcess();

  }

  return 0;
}
