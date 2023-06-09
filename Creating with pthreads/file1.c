#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    int th_n = *(int*)arg;
    int i;
    for(i = 0; i < 10; i++){
        printf("Flow number: %d\n", th_n);
    }
    return NULL;
}

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Using thr: %s\n",argv[0]);
        return 1;
    }

    int nth = atoi(argv[1]);
    pthread_t* thr = malloc(nth * sizeof(pthread_t));
    int* thr_n = malloc(nth * sizeof(int));
    for(int i = 0; i < nth; i++) {
        thr_n[i] = i;
        pthread_create(&thr[i], NULL, thread_func, &thr_n[i]);
    }
    for(int i = 0; i < nth; i++) {
        pthread_join(thr[i], NULL);
    }
    free(thr);
    free(thr_n);
    return 0;
}