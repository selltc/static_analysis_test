#include "all.h"

// this is straight from the example of rule c:S3584

int fun() {
  char* name = (char *) malloc (99);
  if (!name) {
    return 1;
  }
  return 0;
  // SQ will correctly report a memory leak here
}

void main()
{
    fun();
}
