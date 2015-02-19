#include "kt/types.h"

__attribute__ ((section (".stack")))
t_uint8 stack[0x100];

void kernel(void)
{
  // #1 set the stack and the frame
  // #2 have fun

  while (E_TRUE)
    ;
}
