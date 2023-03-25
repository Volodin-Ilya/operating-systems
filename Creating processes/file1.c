#include <stdio.h>
#include <unistd.h>

int main() {
    __pid_t pid, ppid;
    pid = getpid();
    ppid = getppid();
    printf("ID of the current process: %d\n", pid);
    printf("Parent process ID: %d\n", ppid);
    return 0;
}