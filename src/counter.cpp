#include "../include/counter.h"

/**
 * increase counter by 1 and return new value
 */
int Counter::inc()
{
    return ++count;
}

/**
 * decrease counter by 1 and return new value
 */
int Counter::dec()
{
    return --count;
}
