#include <stdio.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

key_t key = 125;

int main(){

    pid_t process = fork();
    int a = shmget(key,50,IPC_CREAT|0666);


}
