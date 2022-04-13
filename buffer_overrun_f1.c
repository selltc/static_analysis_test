#include "all.h"

struct test_struct
{
    char *s;
};

static void f1(struct test_struct *p)
{
    memcpy_s(p->s,10,"1234567890",10);
    // SonarQube FAILS TO REPORT 'Memory copy function overflows the destination buffer' !!
    // This is apparently because we have lied about the destination buffer size, reporting 10,
    // and SonarQube believed us!  (change above to a simple memcpy(), and SQ will correctly
    // find the buffer overflow)
}

void main()
{
    struct test_struct *p=malloc(sizeof(struct test_struct));
    if (p == NULL)
        goto Away;
    p->s = malloc(5);
    if (p->s == NULL)
        goto Away;
    f1(p);
Away:
    ;
}
// SonarQube (correct):  Potential leak of memory pointed to by 'p'
