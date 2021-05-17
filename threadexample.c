#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



void *thread1(void *a){


  int x;
  for( x = 0; x < 10; ++x){

    printf("This is Thread1 ....%d\n", x);
    sleep(1);
  }

  return NULL;

}



void *thread2(void *a){


  int x;
  for( x = 0; x < 10; ++x){

    printf("This is Thread2 ....%d\n", x);
    sleep(2);
  }

  return NULL;

}



int main(){


  pthread_t tid1, tid2;

  if(pthread_create(&tid1, NULL, thread1, NULL)){

    printf("\n Error creating thread1" );
    exit(1);

}

  if(pthread_create(&tid2, NULL, thread2, NULL)){

    printf("\n Error creating thread1" );
    exit(1);

}
    if(pthread_join(tid1, NULL)){

      printf("\n Error joining thread1" );
    }
    pthread_exit(NULL);
    if(pthread_join(tid2, NULL)){

      printf("\n Error joining thread1" );
    }
    pthread_exit(NULL);
}


// gcc thread.c -lpthread
// ./a.out
