#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Please use: %s <pid>< signal> \n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    int signal = atoi(argv[2]);

    if(kill(pid, signal) == -1) {
        printf("Invalid sendig signal\n");
        return 1;
    }

    return 0;
}