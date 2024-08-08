#include <pthread.h>
#include <stdio.h>
#include <limits.h>

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m3 = PTHREAD_MUTEX_INITIALIZER;

double avg;
int min;
int max;
int num[] = {1,3,5,6,0,9};

void *calc_avg(void* args){
    int sum = 0;
    int i;
    for(i=0;i<(sizeof(num)/sizeof(int));i++){
        sum += num[i];
    }
    pthread_mutex_lock(&m1);
    avg = (double) sum/i;
    pthread_mutex_unlock(&m1);
}

void *calc_min(void* args){
    int n = INT_MAX;
    int i;
    for(i=0;i<(sizeof(num)/sizeof(int));i++){
        if(num[i] < n)
            n = num[i];
    }
    pthread_mutex_lock(&m2);
    min = n;
    pthread_mutex_unlock(&m2);
}

void *calc_max(void* args){
    int n = 0;
    int i;
    for(i=0;i<(sizeof(num)/sizeof(int));i++){
        if(num[i] > n)
            n = num[i];
    }
    pthread_mutex_lock(&m3);
    max = n;
    pthread_mutex_unlock(&m3);
}
int main(){
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,calc_avg,NULL);
    pthread_create(&t2,NULL,calc_min,NULL);
    pthread_create(&t3,NULL,calc_max,NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    
    printf("%lf %d %d",avg,min,max);
}
