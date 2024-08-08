#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(){
    int q = open("file.txt",O_CREAT|O_TRUNC|O_RDWR,S_IRWXU);
    char string[] = "This is a string";
    char str[100];
    write(q,string,strlen(string));
    lseek(q,0,SEEK_SET);
    read(q,str,strlen(string));
    write(1,str,sizeof(str));
}
