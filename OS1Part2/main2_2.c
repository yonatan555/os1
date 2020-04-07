#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include <sched.h>
#include<unistd.h>
char child_stack [10000+1];
int c = 0 ;
void add(){
    for(int i =0 ; i<20;i++) {
        c++;
        printf("%d ,", c);
    }
    printf("\n");
  sleep(10);
}
int child(void *parm){
    printf("child_thread--added+1\n");
    add();
}
int grand_child(void *parm){
    printf("grand_child_thread--added+1\n");
    add();
}
int main() {
    int id = clone(child, child_stack + 10000, CLONE_PARENT, 0);
    int id2 = clone(grand_child, child_stack + 10000, CLONE_PARENT, 0);
    printf("clone result:%d\n ", id);
    printf("parent_thread_added+1\n");
    add();
    return 0;
}