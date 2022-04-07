#include "all.h"

struct test_struct
{
    char open_ended_array[1];
};

#define ARRAYBYTES 99
char static_array[ARRAYBYTES];

static void try_malloc(size_t bytes)
{
    struct test_struct *p1;
    size_t total_bytes = sizeof(struct test_struct)+(bytes-1);  // size test_struct needs to be in order
                                                                // for p1->open_ended_array to have space
                                                                // for <bytes> bytes
    p1 = (struct test_struct *)(malloc(total_bytes)); // allocate p1 so that it is big enough to
    if (p1 == NULL)                                   // put exactly <bytes> into p1->open_ended_array
    {   printf("malloc %zu bytes failed!\n", total_bytes); return; }
    p1->open_ended_array[0] = 2;  // see if this affects the report of a memory leak

    // SQ will correctly report a memory leak here
}

void main()
{
    try_malloc(5);
}
