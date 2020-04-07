#include<stdio.h>
#include<stdlib.h>
#include <syslog.h>
#include<unistd.h>

int main(){
    pid_t id = fork();
    if(id == 0  ){
        chdir("/");

    setsid();

    printf("starting...\n");

    close(stdout);
    close(stdin);
    close(stderr);

    openlog("MyDeeamonY",LOG_PID,LOG_DAEMON);
    syslog(LOG_NOTICE,"started...");
    sleep(5);
    syslog(LOG_NOTICE,"doing some work...");
    sleep(5);
    syslog(LOG_NOTICE,"deamon finished...");
    sleep(5);

    }else{
        printf("daemon PID %d\n",id);
    }
    return 0;
}