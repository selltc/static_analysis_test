#include "all.h"

struct test_struct
{
    char *s;
};

static void f4(struct test_struct *p)
{
    strcpy(p->s,"12345");
    // SonarQube (correct):  String copy function overflows the destination buffer
}

void main()
{
    struct test_struct *p=malloc(sizeof(struct test_struct));
    if (p == NULL)
        goto Away;
    p->s = malloc(5);
    if (p->s == NULL)
        goto Away;
    f4(p);
Away:
    ;
}
// SonarQube (correct):  Potential leak of memory pointed to by 'p'
