#include "all.h"

struct test_struct
{
    char *s;
};

static void baseline(struct test_struct *p)
{
    memcpy(p->s,"12345",5);
    memcpy_s(p->s,5,"12345",5);
    strcpy_s(p->s,5,"12345");
    strcpy(p->s,"1234");
    // SonarQube (correct):  no problems reported above
}

void main()
{
    struct test_struct *p=malloc(sizeof(struct test_struct));
    if (p == NULL)
        goto Away;
    p->s = malloc(5);
    if (p->s == NULL)
        goto Away;
    baseline(p);
Away:
    ;
}
// SonarQube (correct):  Potential leak of memory pointed to by 'p'
