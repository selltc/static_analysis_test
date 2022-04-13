#include "all.h"

struct test_struct
{
    char *s;
};

static void f3(struct test_struct *p)
{
    p->s[10] = '\0';
    // SonarQube (correct):  Out of bound memory access (access exceeds upper limit of memory block)
}

void main()
{
    struct test_struct *p=malloc(sizeof(struct test_struct));
    if (p == NULL)
        goto Away;
    p->s = malloc(5);
    if (p->s == NULL)
        goto Away;
    f3(p);
Away:
    ;
}
// SonarQube (correct):  Potential leak of memory pointed to by 'p'
