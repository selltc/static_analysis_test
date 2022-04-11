#include "all.h"

struct test_struct
{
    char open_ended_array[1];
};

static void f_nothing_wrong()
{
    struct test_struct *p;
    size_t bytes = 50;
    size_t total_bytes = sizeof(struct test_struct)+(bytes-1);
    p = (struct test_struct *)(malloc(total_bytes));
    if (p == NULL) return;
    strncpy(&(p->open_ended_array[0]), "hello_world", 20);
    free(p);
}

static void f_easy1()
{
    struct test_struct *p;
    size_t bytes = 5;
    size_t total_bytes = sizeof(struct test_struct)+(bytes-1);
    p = (struct test_struct *)(malloc(total_bytes));
    if (p == NULL) return;
    strncpy(&(p->open_ended_array[0]), "hello_world", 20);
}

static void f_easy2()
{
    struct test_struct *p;
    size_t bytes = 5;
    size_t total_bytes = sizeof(struct test_struct)+(bytes-1);
    p = (struct test_struct *)(malloc(total_bytes));
    if (p == NULL) return;
    strncpy_s(&(p->open_ended_array[0]), 20, "hello_world", 20);
}

static void f_easy3()
{
    struct test_struct *p;
    size_t bytes = 5;
    size_t total_bytes = sizeof(struct test_struct)+(bytes-1);
    p = (struct test_struct *)(malloc(total_bytes));
    if (p == NULL) return;
    memcpy_s(&(p->open_ended_array[0]), 20, "hello_world", 20);
}

static void f_easy4()
{
    struct test_struct *p;
    size_t bytes = 5;
    size_t total_bytes = sizeof(struct test_struct)+(bytes-1);
    p = (struct test_struct *)(malloc(total_bytes));
    if (p == NULL) return;
    p->open_ended_array[10] = 0;
}

static void f_easier()
{
    size_t bytes = 5;
    char *p = malloc(bytes);
    if (p == NULL) return;
    p[10] = 0;
}

static void f_easiest()
{
    char *p = malloc(5);
    if (p == NULL) return;
    p[10] = 0;
}

void main()
{
    f_nothing_wrong();
    f_easy1();
    f_easy2();
    f_easy3();
    f_easy4();
    f_easier();
    f_easiest();
}
