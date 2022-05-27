#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int status;

    printf("Hello, world!\n");

    if (fork()) {
        printf("This is the parent, pid %d.\n", getpid());
    }
    else {
        printf("This is the child, pid %d.\n", getpid());
        return 0;
    }

    wait(&status);
    printf("This is the parent, pid %d, signing off.\n", getpid());
    return 0;
}

