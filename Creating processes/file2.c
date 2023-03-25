#include <stdio.h>
#include <unistd.h>

int main() {
    __pid_t pid = fork();
    if (pid < 0) {
        printf("Error:fork failed\n");
        return 1;
    }
    else if(pid == 0) {
        printf("New process ID: %d. ID of the new parent process: %d.\n", getpid(), getppid());
    }
    else {
        printf("Source process ID: %d. The ID of the original parent process: %d.\n", getpid(), pid);
    }
    return 0;
}