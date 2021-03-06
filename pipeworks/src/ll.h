#ifndef PRIVATE_LL_H
#define PRIVATE_LL_H

#ifndef _MSC_VER
#include <stdatomic.h>
#else
#include "stdatomic.h"
#endif

#include <pipeworks/pw-std.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct ll_node
{
    struct ll_node *next;
    void *value;
    pw_bool occupied;
} ll_node;

typedef struct ll
{
    ll_node *first;
    ll_node *last;
    atomic_size_t size;
} ll;

ll* ll_init();
void ll_push(ll*, void*);
void ll_foreach(ll*, void(*)(void*));
void ll_free(ll*);

#ifdef __cplusplus
}
#endif

#endif
