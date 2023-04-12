#include <stdio.h>
#include <pthread.h>

void* fun(void* arg) {
    printf("sistem prog!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    int i;
    for(i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, fun, NULL);
    }
    pthread_exit(NULL);
    return 0;
}
