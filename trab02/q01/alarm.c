#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler()
{
  printf("received signal after 5 seconds.\n");
}

int main () {
    pid_t child_pid;
    child_pid = fork ();
    if (child_pid != 0) {
        if(signal(SIGALRM, handler) == SIG_ERR) {
            printf("Error settting SIGALRM\n");
            exit(1);
        }
        printf ("parent waiting for alarm.\n");
        pause();
        printf("exiting.\n");
        exit(0);

    } else {
        printf("child sleep.\n");
        sleep(5);
        printf("child woke up.\n");
        kill(getppid(),SIGALRM);
    }
    return 0;
}
