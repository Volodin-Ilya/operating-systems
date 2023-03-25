#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    char *args[] = {"./executable", NULL};
    pid = fork();
    if(pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0) {
        printf("Child: PID = %d, PPID = %d\n", getpid(), getppid());
        if(execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else {
        printf("Parent: PID = %d, PPID = %d\n", getpid(), getppid());
    }
    return 0;
}