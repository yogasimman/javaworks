#include <stdio.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

key_t key = 124;

struct msgbuf {
    long point;
    char *text; // Changed to char pointer
};

typedef struct msgbuf MsgBuf;

int main() {
    int queue_id = msgget(key, IPC_CREAT | 0666); // Create or access the message queue
    if (queue_id == -1) {
        perror("msgget");
        return 1;
    }
    
    pid_t process = fork();
    if (process == 0) {
        sleep(5);
        pid_t q = fork();
        if (q == 0) {
            execlp("gcc", "msgrcv.c", "-o", "m.out", NULL); // Compile msgrcv.c
        } else {
            wait(NULL);
            execlp("./m.out", "./m.out", NULL); // Execute m.out
        }
    } else if (process > 0) {
        wait(NULL);
        
        MsgBuf message;
        message.point = 1;
        char hello[] = "This is a text";
        message.text = strdup(hello); // Assigning string to char pointer
        
        int ret = msgsnd(queue_id, &message, sizeof(message), 0); // Send the message
        if (ret == -1) {
            perror("msgsnd");
            return 1;
        }
        
        // Free the allocated memory
        free(message.text);
    } else {
        perror("fork");
        return 1;
    }
    
    return 0;
}

