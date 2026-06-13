#include <stdio.h>
#include "header.h"

void Buffer_Init(RingBuffer *rb)
{
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

int Buffer_IsFull(RingBuffer *rb)
{
    return (rb->count == BUFFER_SIZE);
}

int Buffer_IsEmpty(RingBuffer *rb)
{
    return (rb->count == 0);
}

uint8_t Buffer_Count(RingBuffer *rb)
{
    return rb->count;
}

int Buffer_Insert(RingBuffer *rb, uint8_t data)
{
    if (Buffer_IsFull(rb))
    {
        return -1;
    }

    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count++;

    return 0;
}

int Buffer_Remove(RingBuffer *rb, uint8_t *data)
{
    if (Buffer_IsEmpty(rb))
    {
        return -1;
    }

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count--;

    return 0;
}