ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

__stack_end__ = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
  .text : {
    KEEP(*(.isr_vector))
    *(.text*)
    *(.rodata*)
  } > FLASH

  .data : {
    __data_start__ = .;  
    *(.data*)
    __data_end__ = .;  
  } > RAM AT > FLASH

    __data_load__ = LOADADDR(.data);

  .bss : {
    __bss_start__ = .;  
    *(.bss*)
    *(COMMON)
    __bss_end__ = .;    
  } > RAM
}
