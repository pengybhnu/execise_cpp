#ifndef __SYNCHRONIZATION__
#define __SYNCHRONIZATION__

#include <limits.h>
#include <linux/futex.h>
#include <sys/syscall.h>
#include <unistd.h>

#include "assembly.h"
#include "types.h"

typedef unsigned int mutex;
typedef struct condvar condvar;

struct condvar {
  mutex *m;
  int seq;
};

void mutex_init(mutex *m) { *m = 0; }

void mutex_destroy(mutex *m) { *m = 0; }

void mutex_lock(mutex *m) {
  mutex c;
  if ((c = __sync_val_compare_and_swap(m, 0, 1)) != 0) {
    do {
      if ((c == 2) || __sync_val_compare_and_swap(m, 1, 2) != 0)
        syscall(SYS_futex, m, FUTEX_WAIT_PRIVATE, 2, NULL, NULL, 0);
    } while ((c = __sync_val_compare_and_swap(m, 0, 2)) != 0);
  }
}

void mutex_unlock(mutex *m) {
  if (__sync_fetch_and_sub(m, 1) != 1) {
    *m = 0;
    syscall(SYS_futex, m, FUTEX_WAKE_PRIVATE, 1, NULL, NULL, 0);
  }
}

void cond_init(condvar *c, mutex *m) {
  c->m = m;
  c->seq = 0;
}

void cond_destroy(condvar *c) {
  c->m = NULL;
  c->seq = 0;
}

void cond_signal(condvar *c) {
  __sync_fetch_and_add(&(c->seq), 1);
  syscall(SYS_futex, &(c->seq), FUTEX_WAKE_PRIVATE, 1, NULL, NULL, 0);
}

void cond_broadcast(condvar *c) {
  __sync_fetch_and_add(&(c->seq), 1);
  syscall(SYS_futex, &(c->seq), FUTEX_REQUEUE_PRIVATE, 1, (void *)INT_MAX, c->m,
          0);
}

void cond_wait(condvar *c) {
  mutex oldSeq = c->seq;
  mutex_unlock(c->m);
  syscall(SYS_futex, &(c->seq), FUTEX_WAIT_PRIVATE, oldSeq, NULL, NULL, 0);
  while (xchg32(c->m, 2)) {
    syscall(SYS_futex, c->m, FUTEX_WAIT_PRIVATE, 2, NULL, NULL, 0);
  }
}

#endif