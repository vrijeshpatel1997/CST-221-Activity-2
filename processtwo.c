#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>

extern char **environ;



void run_cmd(char *cmd)
{

  pid_t pid;

  char *argv[] = {"sh", "-c", cmd, NULL};
  int status;

  printf("Running command ......%s\n",cmd );
  status = posix_spawn(&pid, "/bin/sh", NULL,NULL,argv, environ);
  if(status == 0)
  {

    printf("child process ID (PID) is : %i\n", pid );
    if(waitpid(pid, &status, 0) != -1)
    {


printf("child process exited with status of %i\n",status );
}
 else

 {

  perror(" failed to wait for child process");
}
}
else{

  printf("child process failed to spawn  with error of  '%s'\n",strerror(status) );
}
  }


  int main(int argc, char* argv[]){

  run_cmd(argv[1]);
  return 0;


}
