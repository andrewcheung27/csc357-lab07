#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    pid_t pid;
    int status;

    if (argc != 2) {
        fprintf(stderr, "usage: tryit command\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (!pid) {
        execl(argv[1], argv[1], NULL);
        /* error message if exec returns */
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    /* report on child's status */
    wait(&status);
    if (WEXITSTATUS(status) == 0) {
        printf("Process %d succeeded.\n", pid);
    }
    else {
        printf("Process %d exited with an error value.\n", pid);
    }

    /* exit with child's status */
    exit(WEXITSTATUS(status));
}

