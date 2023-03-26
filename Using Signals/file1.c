#include <stdio.h>
#include <signal.h>
#include <unistd.h>

char* messages = "Waiting signals";

void signal_handler(int signal) {

    if(signal == SIGUSR1) {
        printf("S1 \n");
    }
    else if(signal == SIGUSR2) {
        printf("S2 \n");
    }
}
int main() {

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    
    while(1) {
        printf("%s\n", messages);
        sleep(1);
    }
    return 0;
}