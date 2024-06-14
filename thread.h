#ifndef THREAD_H
#define THREAD_H

int thread_create(void (*fcn)(void *, void *), void *arg1, void *arg2);
int thread_join(void);

#endif
