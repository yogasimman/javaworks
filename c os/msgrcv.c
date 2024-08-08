#include <stdio.h>
#include <sys/msg.h>

key_t key = 124;

struct msgbuf {
    long point;
    char text[126];
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s size\n", argv[0]);
        return 1;
    }
    
    int size_r = atoi(argv[1]);
    int queue_id = msgget(key, 0666);
    if (queue_id == -1) {
        perror("msgget");
        return 1;
    }
    
    struct msgbuf message;
    int size = msgrcv(queue_id, &message, size_r, 1, 0);
    if (size == -1) {
        perror("msgrcv");
        return 1;
    }
    
    printf("%s\nSize: %d\n", message.text, size);
    
    return 0;
}

