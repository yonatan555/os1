#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void forkExample()
{
    // child process if it return 0  value
    pid_t pid= fork();
    if ( pid == 0){

        pid_t pid= fork();
        sleep(5);
        if(pid == 0){
            printf("\n\nHello from grand-Child!\nNumber of Id:  %d\n", getpid());
            printf("My parent is: %d\n",getppid());
            sleep(5);
        }
        else{
            sleep(5);
            printf("\nHello from Child!\nNumber of Id: %d", getpid());
            printf("\nMy parent is: %d",getppid());
        }
    }
        // parent process if it return a value that diffrent from 0
    else{
        sleep(5);
        printf("Hello from Parent! \nNumber of Id: %d\n", getpid());
        printf("My parent is: %d\n",getppid());
}
}
int main()
{
    forkExample();
    return 0;
} 