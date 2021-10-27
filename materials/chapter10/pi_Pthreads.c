#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 4 //假设线程数目为4
int num_steps = 1000000;
double step = 0.0, sum = 0.0;
pthread_mutex_t mutex;

void *countPI(void *id) {
    int index = (int ) id;
    int start = index*(num_steps/NUM_THREADS);
    int end;
    double x = 0.0, y = 0.0;
    if (index == NUM_THREADS-1)
        end = num_steps;
    else
        end = start+(num_steps/NUM_THREADS);

    for (int i=start; i<end; i++){
        x=(i+0.5)*step;
        y +=4.0/(1.0+x*x);
    }

    pthread_mutex_lock(&mutex);
    sum += y;
    pthread_mutex_unlock(&mutex);
}

int main() {
    int i;
    double pi;
    step = 1.0 / num_steps;
    sum = 0.0;
    pthread_t tids[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

    for(i=0; i<NUM_THREADS; i++) {
        pthread_create(&tids[i], NULL, countPI, (void *) i);
    }
    for(i=0; i<NUM_THREADS; i++){
        pthread_join(tids[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pi = step*sum;
    printf("pi %1f\n", pi);
    return 0;
}
