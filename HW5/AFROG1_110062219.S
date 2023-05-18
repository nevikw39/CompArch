# Refernce : https://atcoder.jp/contests/dp/tasks/dp_a
.data
.align 4

# ==============testcase0==============
arr: .word 1028, 23571, 1393, 16572, 5630, 209, 22528, 30466, 11322, 14100, 7469, 4170, 28773, 10083, 5375, 2260, 7024, 271, 5612, 16814, 10602, 262, 20161, 24996, 633
n: .word 25
str: .string "output: "
# output: 87617
# =====================================

# ==============testcase1==============
# arr: .word 10, 30, 40, 20
# n: .word 4
# str: .string "output: "
# output: 30
# =====================================

# ==============testcase2==============
# arr: .word 30, 10, 60, 10, 60, 50 
# n: .word 6
# str: .string "output: "
# output: 40
# =====================================

.text
.global _start
# Start your coding below, don't change anything upper except testing different testcase
_start:
    la a0, arr

    # // s2 = abs(a0[-1] - a0[-2]);
    lw s4, 0(a0)
    lw s5, 4(a0)
    lw a1, n # Reorder to avoid load-use hazard
    li s1, 0 # Reorder to avoid load-use hazard
    sub s2, s4, s5
    srai t0, s2, 63
    xor t1, s2, t0
    sub s2, t1, t0

    addi a0, a0, 8  # a0 += 2 * sizeof(int)
    addi a1, a1, -2 # a1 -= 2

    beq a1, zero, loop_tail

loop:
    mv s3, s4
    mv s4, s5
    lw s5, 0(a0)

    mv s0, s1
    mv s1, s2

    # // t0 = dp[i - 1] + abs(arr[i] - arr[i - 1]);
    sub t0, s5, s4
    srai t2, t0, 63
    xor t3, t0, t2
    sub t0, t3, t2
    add t0, s1, t0

    # // t1 = dp[i - 2] + abs(arr[i] - arr[i - 2]);
    sub t1, s5, s3
    srai t2, t1, 63
    xor t3, t1, t2
    sub t1, t3, t2
    add t1, s0, t1

    # // s2 = min(t0, t1);
    xor t2, t0, t1
    slt t3, t0, t1
    sub t3, zero, t3
    and t2, t2, t3
    xor s2, t1, t2

    addi a0, a0, 4  # a0 += sizeof(int)
    addi a1, a1, -1 # a1--

    bne a1, zero, loop
loop_tail:

    la a0, str
    li a7, 4
    ecall

    mv a0, s2
    li a7, 1
    ecall
