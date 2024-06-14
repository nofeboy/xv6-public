#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"

void wrapper(void *arg1, void *arg2){
    int new = 100;
    *(int *)arg1 = new;
}

int main(){
    int a = 0;
    int tid = thread_create(wrapper, (void *)&a, 0);
    if(tid == -1){
        printf(1, "Error: thread_create failed\n");
        exit();
    }
    tid = thread_join();
    if(tid == -1){
        printf(1, "Error: thread_join failed\n");
        exit();
    }
    if(a != 100){
        printf(1, "Error: thread did not set value correctly\n");
        exit();
    }
    printf(1, "Value of a: %d\n", a);  // a의 값을 출력
    printf(1, "Test passed\n");
    exit();
}
