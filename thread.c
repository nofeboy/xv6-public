#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"

#define PGSIZE 4096

int thread_create(void (*fcn)(void *, void *), void *arg1, void *arg2) {
    void *stack = malloc(PGSIZE * 2);
    if((uint)stack % PGSIZE)
        stack = stack + (PGSIZE - (uint)stack % PGSIZE);
    int tid = clone(fcn, arg1, arg2, stack);
    if(tid == -1)
        free(stack);
    return tid;
}

int thread_join(void) {
    void *stack;
    int tid = join(&stack);
    if(tid != -1)
        free(stack);
    return tid;
}
