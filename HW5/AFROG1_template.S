# Refernce : https://atcoder.jp/contests/dp/tasks/dp_a
.data
.align 4

# ==============testcase1==============
arr: .word 10, 30, 40, 20
n: .word 4
str: .string "output: "
# output: 30
# =====================================

# ==============testcase2==============
#arr: .word 30, 10, 60, 10, 60, 50 
#n: .word 6
#str: .string "output: "
# output: 40
# =====================================

.text
.global _start
# Start your coding below, don't change anything upper except testing different testcase
_start:
    la s2, arr
    lw s3, n
    li a7, 1

loop:
    lw a0, 0(s2)
    ecall
    addi s2,s2,4
    addi s3,s3,-1
    bgt s3,zero,loop

    li a7, 10
    ecall
