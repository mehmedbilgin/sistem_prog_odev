#include <stdlib.h>
#include <stdio.h>

#include <unistd.h> /* defines _POSIX_THREADS if pthreads are available */
#ifdef _POSIX_THREADS
# include <pthread.h>
#endif

#include <semaphore.h>
sem_t semafor;
void *text(void *arg);

int code[] = { 4, 6, 3, 1, 5, 0, 2 };

int main()
{
    sem_init(&semafor,0,1);
  int i;
  pthread_t tid[7];

  for (i = 0; i < 7; i++)
    pthread_create(&tid[i], NULL, text, (void*)&code[i]);

    sem_destroy(&semafor);
  return 0;
}

void *text(void *arg)
{
    sem_wait(&semafor);
  int n = *(int*)arg;

  switch (n)
  {
    case 0:
      printf("6A semaphore S is an integer-valued variable which can take only non-negative\n");
      printf("values. Exactly two operations are defined on a semaphore:\n\n");
      sem_post(&semafor);
      break;

    case 1:
      printf("4Signal(S): If there are processes that have been suspended on this semaphore,\n");
      printf(" wake one of them, else S := S+1.\n\n");
      sem_post(&semafor);
      break;

    case 2:
      printf("7Wait(S): If S>0 then S:=S-1, else suspend the execution of this process.\n");
      printf(" The process is said to be suspended on the semaphore S.\n\n");
      sem_post(&semafor);
      break;

    case 3:
      printf("3The semaphore has the following properties:\n\n");
      sem_post(&semafor);
      break;

    case 4:
      printf("1. Signal(S) and Wait(S) are atomic instructions. In particular, no\n");
      printf(" instructions can be interleaved between the test that S>0 and the\n");
      printf(" decrement of S or the suspension of the calling process.\n\n");
      sem_post(&semafor);
      break;

    case 5:
      printf("5. A semaphore must be given an non-negative initial value.\n\n");
      sem_post(&semafor);
      break;

    case 6:
      printf("2. The Signal(S) operation must waken one of the suspended processes. The\n");
      sem_post(&semafor);
      break;
      
  }
}
