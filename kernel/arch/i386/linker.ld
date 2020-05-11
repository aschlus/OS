/* Start execution at _start */
ENTRY(_start)

/* Tell linker where sections of the object files will be put in the kernel image */
SECTIONS
{
    /* Begin putting sections at 1 MiB */
    . = 1M;

    /* First put the multiboot header, then text */
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text)
    }

    /* Read-only data */
    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    /* Read-write data (initialized) */
    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    /* Read-write data (uninitialized) and stack */
    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }
}
