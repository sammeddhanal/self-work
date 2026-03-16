#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef struct
{
    uint8_t *buffer;
    size_t size;
    size_t head;
    size_t tail;
} ring_buffer_t;

/* Initialize ring buffer */
int rb_init(ring_buffer_t *rb, uint8_t *buffer, size_t size)
{
    if (rb == NULL || buffer == NULL || size < 2)
        return -1;

    rb->buffer = buffer;
    rb->size = size;
    rb->head = 0;
    rb->tail = 0;

    return 0;
}

/* Push data into buffer */
int rb_push(ring_buffer_t *rb, uint8_t data)
{
    size_t next = (rb->head + 1) % rb->size;

    if (next == rb->tail)
    {
        return -1; // Buffer Full
    }

    rb->buffer[rb->head] = data;
    rb->head = next;

    return 0;
}

/* Pop data from buffer */
int rb_pop(ring_buffer_t *rb, uint8_t *data)
{
    if (rb->head == rb->tail)
    {
        return -1; // Buffer Empty
    }

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % rb->size;

    return 0;
}

/* Test program */
int main()
{
    uint8_t storage[5]; // fixed buffer (no dynamic memory)
    ring_buffer_t rb;
    uint8_t value;

    if (rb_init(&rb, storage, 5) != 0)
    {
        printf("Initialization failed\n");
        return -1;
    }

    /* Push elements */
    printf("Pushing values:\n");
    for (int i = 1; i <= 5; i++)
    {
        if (rb_push(&rb, i * 10) == 0)
            printf("Pushed %d\n", i * 10);
        else
            printf("Buffer Full! Cannot push %d\n", i * 10);
    }

    /* Pop elements */
    printf("\nPopping values:\n");
    while (rb_pop(&rb, &value) == 0)
    {
        printf("Popped %d\n", value);
    }

    printf("Buffer Empty\n");

    return 0;
}
