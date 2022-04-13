#include "all.h"

struct test_struct
{
    char *s;
};

static void f2(struct test_struct *p)
{
    strcpy_s(p->s,10,"1234567890");
    // SonarQube FAILS TO REPORT 'String copy function overflows the destination buffer' !!
    // This is apparently because we have lied about the destination buffer size, reporting 10,
    // and SonarQube believed us!  (change above to a simple strcpy(), and SQ will correctly
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
    f2(p);
Away:
    ;
}
// SonarQube (correct):  Potential leak of memory pointed to by 'p'
