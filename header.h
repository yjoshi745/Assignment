#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>

#define BUFFER_SIZE 8

typedef struct
{
    uint8_t buffer[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
} RingBuffer;

void Buffer_Init(RingBuffer *rb);

int Buffer_Insert(RingBuffer *rb, uint8_t data);

int Buffer_Remove(RingBuffer *rb, uint8_t *data);

int Buffer_IsFull(RingBuffer *rb);

int Buffer_IsEmpty(RingBuffer *rb);

uint8_t Buffer_Count(RingBuffer *rb);

#endif