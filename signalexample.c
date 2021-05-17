#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <err.h>
#include <errno.h>


int WAKEUP =SIGUSR1;


pid_t otherPid;

sigset_t sigset;




void sleepUnitWoken()
{

  int nSig;

printf("sleeping ....\n" );
sigwait(&sigset, &nSig);

printf("AWOKEN ....\n" );

}

void consumer(){

  sigemptyset(&sigset);
  sigaddset(&sigset, WAKEUP);
  sigprocmask(SIG_BLOCK, &sigset, NULL);

  printf("putting consumer to sleep forever\n" );
  sleepUnitWoken();

  int count = 0;

  printf("Running  consumer Process ... \n" );
  while(count < 20){
    printf("Consumer %d\n", count );
    sleep(1);
    ++count;

  }

  _exit(1);
}



void producer(){

int count = 0;

printf("Running  producer  Process \n" );


  while(count < 30){
    printf("Prodcuer  %d\n", count );

    sleep(1);
    if(count == 5){

        printf("Waking up the consumer ..... \n" );
        kill(otherPid, WAKEUP);

    }
    ++count;

  }

  _exit(1);
}


int main(int argc, char* argv[])
{

pid_t pid;


pid = fork();
if(pid == -1){

  printf("cant fork, error %d\n", errno );
  exit(EXIT_FAILURE);

}

if(pid == 0)
{

  otherPid = getppid();

  producer();

} else {

  otherPid = pid;
  consumer();

}

return 0;
}
