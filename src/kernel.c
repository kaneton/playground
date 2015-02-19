#include <stdlib.h>
#include "kt/types.h"

__attribute__ ((section (".stack")))
t_uint8 stack[0x100];

void kernel(void)
{
  // #0 this function has a prologue, safe or not depending of the loader
  // #1 isolate yourself by setting the stack and the frame
  // #2 have fun
  malloc(0x1000);

  while (E_TRUE)
    ;
}
