#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#define MAX_SIZE 126
key_t key = 125;
int msgid = msgget(key,0666);
struct msgbuffer{  
    long a;
    char b[MAX_SIZE];

}typedef msgbuffer;

int main(){
    msgbuffer mes;
   int sucess = msgrcv(msgid,mes,MAX_SIZE,1,0);
    if(sucess == -1){ printf("Error in msgrcv");return;}
    printf("Message Recieved: %s",mes.b);
}
