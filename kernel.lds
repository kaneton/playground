ENTRY(kernel)

MEMORY
{
  kernel : org = 1M, len = 16M
}

SECTIONS
{
  /*----------------------------------------------------------------------------*/
  /* RO/Execute Text Sections                                                   */
  /*----------------------------------------------------------------------------*/

  .text :
  {
     PROVIDE(__KERNEL_BEGIN = .);
     PROVIDE(__KERNEL_TEXT_BEGIN = .);
     *(.text)
     *(.text.unlikely)
     PROVIDE(__KERNEL_TEXT_END = .);
  } > kernel

  /*----------------------------------------------------------------------------*/
  /* RO Data Sections                                                           */
  /*----------------------------------------------------------------------------*/

  .rodata ALIGN(4K) :
  {
     PROVIDE(__KERNEL_RODATA_BEGIN = .);
     *(.rodata*)
     *(.fixup)
     *(.got)
     *(.got2)
     PROVIDE(__KERNEL_RODATA_END = .);
  } > kernel

  /*----------------------------------------------------------------------------*/
  /* RW Data Sections                                                           */
  /*----------------------------------------------------------------------------*/

  /*
   * Stack growing down to the RO data section
   */
  .stack ALIGN(4K) (NOLOAD) :
  {
    PROVIDE(__KERNEL_DATA_BEGIN = .);
    *(.stack)
  } > kernel
  ASSERT(SIZEOF(.stack), "stack required")

  .data ALIGN(4K) :
  {
    PROVIDE(__DATA_ROM_BEGIN = .);
    PROVIDE(__DATA_RAM_BEGIN = .);

    *(.data*)
  } > kernel

  .sdata ALIGN(4K) :
  {
    *(.sdata*)
    PROVIDE (__DATA_END = .);
  } > kernel

  .sbss ALIGN(4K) (NOLOAD) :
  {
    PROVIDE (__BSS_BEGIN = .);
    *(.sbss)
  } > kernel

  .bss ALIGN(256) (NOLOAD):
  {
    *(.bss)
    *(COMMON)

    PROVIDE (__BSS_END = .);
  } > kernel

  PROVIDE(__KERNEL_DATA_END = .);

  /*
   * end symbol for newlib sbrk support.
   * __KERNEL_END - end bytes can be allocated when using it.
   */
  PROVIDE(end = .);

  /*
   * Make space for at least 4K of static free memory for sbrk.
   */
  . = . + 1;
  PROVIDE(__KERNEL_END = ALIGN(4K));

  /DISCARD/ : { *(.eh_frame*) }
}
