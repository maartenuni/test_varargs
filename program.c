
#include <stdio.h>
#include "init.h"

int main() {
    int ret;
    two_t two;

    ret = init_two(
        &two,
        INIT_ONE_A,         1,
        INIT_ONE_MSG,       "Hello, world",
        INIT_ONE_FINISHED,
        INIT_TWO_PI,        2 * 3.1415,
        INIT_TWO_FINISHED
    );
    
    if (ret) {
        fprintf(stderr, "unable to init two...\n");
        printf("a=%d\tmsg=%s\tpi=%lf\te%lf\t",
            two.parent.a,
            two.parent.msg,
            two.pi,
            two.e
        );
        return 1;
    }
    else {
        printf("a=%d\tmsg=%s\tpi=%lf\te%lf\t",
            two.parent.a,
            two.parent.msg,
            two.pi,
            two.e
        );
        return 0;
    }
}