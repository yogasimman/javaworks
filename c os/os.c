#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MSGSIZE 128 // Define the maximum size of the message

key_t key = 125;

struct msgbuf {
    long mtype;
    char mtext[MSGSIZE];
};

int main() {
    pid_t node = fork();
    if (node < 0) {
        perror("fork failed");
        return 1;
    }
    else if (node > 0) {
        // Parent process
        int msgid = msgget(key, IPC_CREAT | 0666); // Create or access the message queue
        if (msgid == -1) {
            perror("msgget");
            return 1;
        }
        printf("Message queue created with id: %d\n", msgid);
        
        struct msgbuf buffer;
        buffer.mtype = 1; // Message type
        strcpy(buffer.mtext, "This is a string"); // Copy the message content
        
        int ret = msgsnd(msgid, &buffer, strlen(buffer.mtext) + 1, 0); // Send the message
        if (ret == -1) {
            perror("msgsnd");
            return 1;
        }
        // Wait for the child process to finish
        wait(NULL);
    }
    else {
        // Child process
        pid_t t = fork();
        if (t == 0) {
            char *args[] = {"gcc", "os2.c", "-o", "os2", NULL};
            execvp("gcc", args); 
        }
        else if (t > 0) {
            sleep(4);
            char *args[] = {"./os2", NULL};
            execvp("./os2", args); // Execute the compiled program
            perror("execv failed"); // This line will only execute if execv fails
            return 1;
        }
        else {
            perror("fork failed");
            return 1;
        }
    }

    return 0;
}

