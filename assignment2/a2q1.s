.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, sumSquare

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a0, x0, 10
    ecall # Exit

sumSquare:
	addi sp, sp, -12
    sw ra, 0(sp)
    sw s0, 4(sp)
    sw s1, 8(sp)

    add s0, a0, zero
    add s1, x0, x0
    loop: bge x0, s0, end
    	add a0, s0, x0
	   	jal ra, square
		add s1, s1, a0
		addi s0, s0, -1
		j loop
    end: mv a0 s1
	lw ra, 0(sp)
	lw s0, 4(sp)
	lw s1, 8(sp)
	addi sp, sp, 12
	ret

 square: mul a0, a0, a0
        jr ra