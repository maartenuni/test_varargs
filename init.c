
#include <stdarg.h>
#include "init.h"

static int priv_init1(one_t* one, va_list list)
{
    // use default values;
    int a = 0;
    const char* msg = "";

    int selector, ret = STATUS_SUCCES;

    while ((selector = va_arg(list, int)) != INIT_ONE_FINISHED) {
        switch (selector) {
        case INIT_ONE_A:
            a = va_arg(list, int);
            break;
        case INIT_ONE_MSG:
            msg = va_arg(list, const char*);
            break;
        default:
            // unknown argument
            return STATUS_INVALID_ARGUMENT;
        }
    }

    one->a = a;
    one->msg = msg;
    return ret;
}

static int priv_init2(two_t* two, va_list list)
{
    double pi = 3.1415, e=2.7128;
    int selector, ret = STATUS_SUCCES;

    ret = priv_init1((one_t*)two, list);
    if (ret)
        return ret;

    while ((selector = va_arg(list, int)) != INIT_TWO_FINISHED) {
        switch (selector) {
        case INIT_TWO_PI:
            pi = va_arg(list, double);
            break;
        case INIT_TWO_E:
            pi = va_arg(list, double);
            break;
        default:
            return STATUS_INVALID_ARGUMENT;
        }
    }

    two->pi = pi;
    two->e = e;

    return STATUS_SUCCES;
}

int init_two(two_t* two, ...)
{
    int ret;
    va_list list;
    va_start(list, two);
    ret = priv_init2(two, list);
    va_end(list);

    return ret;
}