#include <stdio.h>
#include <pthread.h>
int x=0,i,j;

void* thread_func1(void* arg) {
    for(i=0;i<5;i++){
        x = x+1;
    }
}
void* thread_func2(void* arg) {
    for(j=0;j<5;j++){
        x = x+2;
    }
}

int main() {
    pthread_t thread1,thread2;
    pthread_create(&thread1, NULL, thread_func1, NULL);
    pthread_create(&thread2, NULL, thread_func2, NULL);
    printf("%d",x);
    return 0;
}
