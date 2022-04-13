#include "all.h"

struct test_struct
{
    char *s;
};

static void f0(struct test_struct *p)
{
    memcpy(p->s,"123456",6);
    // SonarQube (correct):  Memory copy function overflows the destination buffer
}

void main()
{
    struct test_struct *p=malloc(sizeof(struct test_struct));
    if (p == NULL)
        goto Away;
    p->s = malloc(5);
    if (p->s == NULL)
        goto Away;
    f0(p);
Away:
    ;
}
// SonarQube (correct):  Potential leak of memory pointed to by 'p'
