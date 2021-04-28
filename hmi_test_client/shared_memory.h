#ifndef SHARED_MEMORY_H_
#define SHARED_MEMORY_H_

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "types_definitions.h"

void init_shared_memory(void);
void deinit_shared_memory(void);
void write_uint8_value(char option,uint8_t value);
void write_int_value(char option,int value);
void write_float_value(char option,float value);

#endif /* SHARED_MEMORY_H_ */
