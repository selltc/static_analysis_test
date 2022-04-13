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

static void f0(struct test_struct *p)
{
    memcpy(p->s,"123456",6);
    // SonarQube (correct):  Memory copy function overflows the destination buffer
}

static void f1(struct test_struct *p)
{
    memcpy_s(p->s,10,"1234567890",10);
    // SonarQube FAILS TO REPORT 'Memory copy function overflows the destination buffer' !!
}

static void f2(struct test_struct *p)
{
    strcpy_s(p->s,10,"1234567890");
    // SonarQube FAILS TO REPORT 'String copy function overflows the destination buffer' !!
}

static void f3(struct test_struct *p)
{
    p->s[10] = '\0';
    // SonarQube FAILS TO REPORT 'Out of bound memory access (access exceeds upper limit of memory block)' !!
    // There seems to be a problem such that when a problem is reported within a vulnerable code path,
    // as discovered in f0() above, SQ fails to report subsequent problems in the code path.
}

static void f4(struct test_struct *p)
{
    strcpy(p->s,"12345");
    // SonarQube FAILS TO REPORT 'String copy function overflows the destination buffer' !!
    // There seems to be a problem such that when a problem is reported within a vulnerable code path,
    // as discovered in f0() above, SQ fails to report subsequent problems in the code path.
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
    f0(p);
    f1(p);
    f2(p);
    f3(p);
    f4(p);
Away:
    ;
}
// SonarQube (correct):  Potential leak of memory pointed to by 'p'
