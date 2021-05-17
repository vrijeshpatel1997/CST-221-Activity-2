#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_DEPOSITS 1000000

int balance = 0;


void *deposit(void *a)
{

  int x, tmp;

  for(x=0; x < MAX_DEPOSITS; ++x)
  {

    tmp = balance;
    tmp = tmp + 1;
    balance = tmp;

  }

  return NULL;
}


int main()
{

pthread_t tid1, tid2;

if(pthread_create(&tid1, NULL, deposit, NULL))
{

  printf("\n ERRoR creating deposit thread 1" );
  exit(1);

}

if(pthread_create(&tid2, NULL, deposit, NULL))
{

  printf("\n ERRoR creating deposit thread 2" );
  exit(1);
}

if(pthread_join(tid1, NULL))
{

  printf("\n  error joining deposit thread 1" );
  exit(1);
}

if(pthread_join(tid2, NULL))
{

  printf("\n  error joining deposit thread 2" );
  exit(1);
}

if(balance < 2 * MAX_DEPOSITS)
{
    printf("\n BAD Balance : bank balance is $%d and should be $%d\n",balance, 2 * MAX_DEPOSITS );
  }  else{



      printf("\n GOOD  Balance : bank balance is  $%d\n",balance);



      pthread_exit(NULL);
    }
    }

    // gcc bank.c -lpthread
    // ./a.out
