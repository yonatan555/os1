#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

void (*hello_Ariel)(const char *);

bool init()
{
    void *hdl = dlopen("./hello_ariel.so", RTLD_LAZY);
    if (NULL == hdl) return false;
    hello_Ariel = (void(*)(const char *))dlsym(hdl, "hello_Ariel");
    if (NULL ==  hello_Ariel) return false;
    return true;
}
int main(){
    if (init())
        hello_Ariel("Ariel");
    else
        printf ("Libary is not loaded\n");
    return 0;
}
