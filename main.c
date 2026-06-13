#include "header.h"
#include <stdio.h>


int main()
{
    RingBuffer rb;
    uint8_t data;

    Buffer_Init(&rb);

    printf("Writing 8 bytes:\n");

    uint8_t arr[8] =
    {
        0x41, 0x42, 0x43, 0x44,
        0x45, 0x46, 0x47, 0x48
    };

    for(int i = 0; i < 8; i++)
    {
        Buffer_Insert(&rb, arr[i]);
        printf("Written: 0x%X\n", arr[i]);
    }

    printf("\nCount = %d\n", Buffer_Count(&rb));

    if(Buffer_IsFull(&rb))
    {
        printf("Buffer Full\n");
    }

    printf("\nAttempting to write 0x99\n");

    if(Buffer_Insert(&rb, 0x99) == -1)
    {
        printf("Write Failed (Buffer Full)\n");
    }

    printf("\nReading 3 bytes:\n");

    for(int i = 0; i < 3; i++)
    {
        Buffer_Remove(&rb, &data);
        printf("Read: 0x%X\n", data);
    }

    printf("Count = %d\n", Buffer_Count(&rb));

    printf("\nWriting 3 bytes:\n");

    Buffer_Insert(&rb, 0x49);
    Buffer_Insert(&rb, 0x4A);
    Buffer_Insert(&rb, 0x4B);

    printf("Written: 0x49\n");
    printf("Written: 0x4A\n");
    printf("Written: 0x4B\n");

    printf("Count = %d\n", Buffer_Count(&rb));

    printf("\nReading Remaining Bytes:\n");

    while(!Buffer_IsEmpty(&rb))
    {
        Buffer_Remove(&rb, &data);
        printf("Read: 0x%X\n", data);
    }

    if(Buffer_IsEmpty(&rb))
    {
        printf("Buffer Empty\n");
    }

    printf("\nAttempting Read from Empty Buffer\n");

    if(Buffer_Remove(&rb, &data) == -1)
    {
        printf("Read Failed (Buffer Empty)\n");
    }

    return 0;
}