.arm
.align(2);
.section .rodata

@ -- 100% Catch Rate --
.global hooked_catch100
.type hooked_catch100, %function
hooked_catch100:
    LDRB    R0, [R0, #8]
    PUSH    {R0, R1}
    LDR     R0, [SP, #0xC]
    LDR     R1, =catch100_jump
    LDR     R1, [R1]
    CMP     R1, R0
    SUBEQ   R0, R0, #0xF8
    STREQ   R0, [SP, #0xC]
    POP     {R0, R1}
    LDMFD   SP!, {R4, PC}
