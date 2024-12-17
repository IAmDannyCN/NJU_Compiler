.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  la $a0, _prompt
  syscall
  li $v0, 5
  syscall
  jr $ra
write:
  li $v0, 1
  syscall
  li $v0, 4
  la $a0, _ret
  syscall
  move $v0, $0
  jr $ra

                   # FUNCTION Output :
Output:
  addi $sp, $sp, -4
  sw $s8, 0($sp)
  la $s8, 4($sp)
  addi $sp, $sp, -56
# tooutput -> 52($sp)
# sz -> 48($sp)
# _t1 -> 44($sp)
# oi -> 40($sp)
# _t2 -> 36($sp)
# _t3 -> 32($sp)
# _t4 -> 28($sp)
# _t5 -> 24($sp)
# _t6 -> 20($sp)
# tNULL -> 16($sp)
# _t8 -> 12($sp)
# _t9 -> 8($sp)
# _t7 -> 4($sp)
# _t10 -> 0($sp)

                   # PARAM tooutput
  move $t0, $a0
  sw $t0, 52($sp)

                   # PARAM sz
  move $t0, $a1
  sw $t0, 48($sp)

                   # _t1 := #1
  li $t0, 1
  sw $t0, 44($sp)

                   # oi := _t1
  lw $t0, 44($sp)
  sw $t0, 40($sp)

                   # LABEL _L1 :
_L1:

                   # _t2 := oi
  lw $t0, 40($sp)
  sw $t0, 36($sp)

                   # _t3 := sz
  lw $t0, 48($sp)
  sw $t0, 32($sp)

                   #  _t3 GOTO _L2
  lw $t0, 36($sp)
  lw $t1, 32($sp)
  ble $t0, $t1, _L2

                   # GOTO _L3
  j _L3

                   # LABEL _L2 :
_L2:

                   # _t4 := tooutput
  lw $t0, 52($sp)
  sw $t0, 28($sp)

                   # _t5 := #0
  li $t0, 0
  sw $t0, 24($sp)

                   # _t6 := oi
  lw $t0, 40($sp)
  sw $t0, 20($sp)

                   # _t6 := _t6 * #4
  lw $t0, 20($sp)
  li $t1, 4
  mul $t0, $t0, $t1
  sw $t0, 20($sp)

                   # _t5 := _t5 + _t6
  lw $t0, 24($sp)
  lw $t1, 20($sp)
  add $t0, $t0, $t1
  sw $t0, 24($sp)

                   # _t4 := _t4 + _t5
  lw $t0, 28($sp)
  lw $t1, 24($sp)
  add $t0, $t0, $t1
  sw $t0, 28($sp)

                   # _t4 := *_t4
  lw $t0, 28($sp)
  lw $t0, 0($t0)
  sw $t0, 28($sp)

                   # WRITE _t4
  lw $a0, 28($sp)
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0

                   # tNULL := #0
  li $t0, 0
  sw $t0, 16($sp)

                   # _t8 := oi
  lw $t0, 40($sp)
  sw $t0, 12($sp)

                   # _t9 := #1
  li $t0, 1
  sw $t0, 8($sp)

                   # _t7 := _t8 + _t9
  lw $t0, 12($sp)
  lw $t1, 8($sp)
  add $t0, $t0, $t1
  sw $t0, 4($sp)

                   # oi := _t7
  lw $t0, 4($sp)
  sw $t0, 40($sp)

                   # GOTO _L1
  j _L1

                   # LABEL _L3 :
_L3:

                   # _t10 := #0
  li $t0, 0
  sw $t0, 0($sp)

                   # RETURN _t10
  lw $v0, 0($sp)
  move $sp, $s8
  lw $s8, -4($s8)
  jr $ra

                   # FUNCTION swap :
swap:
  addi $sp, $sp, -4
  sw $s8, 0($sp)
  la $s8, 4($sp)
  addi $sp, $sp, -84
# toswap -> 80($sp)
# swapi -> 76($sp)
# swapj -> 72($sp)
# _t11 -> 68($sp)
# _t12 -> 64($sp)
# _t13 -> 60($sp)
# swapival -> 56($sp)
# _t14 -> 52($sp)
# _t15 -> 48($sp)
# _t16 -> 44($sp)
# swapjval -> 40($sp)
# _t17 -> 36($sp)
# _t18 -> 32($sp)
# _t19 -> 28($sp)
# _t20 -> 24($sp)
# tNULL -> 20($sp)
# _t21 -> 16($sp)
# _t22 -> 12($sp)
# _t23 -> 8($sp)
# _t24 -> 4($sp)
# _t25 -> 0($sp)

                   # PARAM toswap
  move $t0, $a0
  sw $t0, 80($sp)

                   # PARAM swapi
  move $t0, $a1
  sw $t0, 76($sp)

                   # PARAM swapj
  move $t0, $a2
  sw $t0, 72($sp)

                   # _t11 := toswap
  lw $t0, 80($sp)
  sw $t0, 68($sp)

                   # _t12 := #0
  li $t0, 0
  sw $t0, 64($sp)

                   # _t13 := swapi
  lw $t0, 76($sp)
  sw $t0, 60($sp)

                   # _t13 := _t13 * #4
  lw $t0, 60($sp)
  li $t1, 4
  mul $t0, $t0, $t1
  sw $t0, 60($sp)

                   # _t12 := _t12 + _t13
  lw $t0, 64($sp)
  lw $t1, 60($sp)
  add $t0, $t0, $t1
  sw $t0, 64($sp)

                   # _t11 := _t11 + _t12
  lw $t0, 68($sp)
  lw $t1, 64($sp)
  add $t0, $t0, $t1
  sw $t0, 68($sp)

                   # _t11 := *_t11
  lw $t0, 68($sp)
  lw $t0, 0($t0)
  sw $t0, 68($sp)

                   # swapival := _t11
  lw $t0, 68($sp)
  sw $t0, 56($sp)

                   # _t14 := toswap
  lw $t0, 80($sp)
  sw $t0, 52($sp)

                   # _t15 := #0
  li $t0, 0
  sw $t0, 48($sp)

                   # _t16 := swapj
  lw $t0, 72($sp)
  sw $t0, 44($sp)

                   # _t16 := _t16 * #4
  lw $t0, 44($sp)
  li $t1, 4
  mul $t0, $t0, $t1
  sw $t0, 44($sp)

                   # _t15 := _t15 + _t16
  lw $t0, 48($sp)
  lw $t1, 44($sp)
  add $t0, $t0, $t1
  sw $t0, 48($sp)

                   # _t14 := _t14 + _t15
  lw $t0, 52($sp)
  lw $t1, 48($sp)
  add $t0, $t0, $t1
  sw $t0, 52($sp)

                   # _t14 := *_t14
  lw $t0, 52($sp)
  lw $t0, 0($t0)
  sw $t0, 52($sp)

                   # swapjval := _t14
  lw $t0, 52($sp)
  sw $t0, 40($sp)

                   # _t17 := swapjval
  lw $t0, 40($sp)
  sw $t0, 36($sp)

                   # _t18 := #0
  li $t0, 0
  sw $t0, 32($sp)

                   # _t19 := swapi
  lw $t0, 76($sp)
  sw $t0, 28($sp)

                   # _t19 := _t19 * #4
  lw $t0, 28($sp)
  li $t1, 4
  mul $t0, $t0, $t1
  sw $t0, 28($sp)

                   # _t18 := _t18 + _t19
  lw $t0, 32($sp)
  lw $t1, 28($sp)
  add $t0, $t0, $t1
  sw $t0, 32($sp)

                   # _t20 := toswap
  lw $t0, 80($sp)
  sw $t0, 24($sp)

                   # _t20 := _t20 + _t18
  lw $t0, 24($sp)
  lw $t1, 32($sp)
  add $t0, $t0, $t1
  sw $t0, 24($sp)

                   # *_t20 := _t17
  lw $t0, 24($sp)
  lw $t1, 36($sp)
  sw $t1, 0($t0)

                   # tNULL := _t17
  lw $t0, 36($sp)
  sw $t0, 20($sp)

                   # _t21 := swapival
  lw $t0, 56($sp)
  sw $t0, 16($sp)

                   # _t22 := #0
  li $t0, 0
  sw $t0, 12($sp)

                   # _t23 := swapj
  lw $t0, 72($sp)
  sw $t0, 8($sp)

                   # _t23 := _t23 * #4
  lw $t0, 8($sp)
  li $t1, 4
  mul $t0, $t0, $t1
  sw $t0, 8($sp)

                   # _t22 := _t22 + _t23
  lw $t0, 12($sp)
  lw $t1, 8($sp)
  add $t0, $t0, $t1
  sw $t0, 12($sp)

                   # _t24 := toswap
  lw $t0, 80($sp)
  sw $t0, 4($sp)

                   # _t24 := _t24 + _t22
  lw $t0, 4($sp)
  lw $t1, 12($sp)
  add $t0, $t0, $t1
  sw $t0, 4($sp)

                   # *_t24 := _t21
  lw $t0, 4($sp)
  lw $t1, 16($sp)
  sw $t1, 0($t0)

                   # tNULL := _t21
  lw $t0, 16($sp)
  sw $t0, 20($sp)

                   # _t25 := #0
  li $t0, 0
  sw $t0, 0($sp)

                   # RETURN _t25
  lw $v0, 0($sp)
  move $sp, $s8
  lw $s8, -4($s8)
  jr $ra

                   # FUNCTION partition :
partition:
  addi $sp, $sp, -4
  sw $s8, 0($sp)
  la $s8, 4($sp)
  addi $sp, $sp, -152
# parr -> 148($sp)
# low -> 144($sp)
# high -> 140($sp)
# _t26 -> 136($sp)
# _t27 -> 132($sp)
# _t28 -> 128($sp)
# pivot -> 124($sp)
# _t30 -> 120($sp)
# _t31 -> 116($sp)
# _t29 -> 112($sp)
# pi -> 108($sp)
# _t32 -> 104($sp)
# pj -> 100($sp)
# _t33 -> 96($sp)
# _t34 -> 92($sp)
# _t35 -> 88($sp)
# _t37 -> 84($sp)
# _t38 -> 80($sp)
# _t36 -> 76($sp)
# _t40 -> 72($sp)
# _t41 -> 68($sp)
# _t39 -> 64($sp)
# _t42 -> 60($sp)
# _t43 -> 56($sp)
# _t44 -> 52($sp)
# tNULL -> 48($sp)
# swap -> 44($sp)
# _t46 -> 40($sp)
# _t47 -> 36($sp)
# _t45 -> 32($sp)
# _t48 -> 28($sp)
# _t50 -> 24($sp)
# _t51 -> 20($sp)
# _t49 -> 16($sp)
# _t52 -> 12($sp)
# _t54 -> 8($sp)
# _t55 -> 4($sp)
# _t53 -> 0($sp)

                   # PARAM parr
  move $t0, $a0
  sw $t0, 148($sp)

                   # PARAM low
  move $t0, $a1
  sw $t0, 144($sp)

                   # PARAM high
  move $t0, $a2
  sw $t0, 140($sp)

                   # _t26 := parr
  lw $t0, 148($sp)
  sw $t0, 136($sp)

                   # _t27 := #0
  li $t0, 0
  sw $t0, 132($sp)

                   # _t28 := high
  lw $t0, 140($sp)
  sw $t0, 128($sp)

                   # _t28 := _t28 * #4
  lw $t0, 128($sp)
  li $t1, 4
  mul $t0, $t0, $t1
  sw $t0, 128($sp)

                   # _t27 := _t27 + _t28
  lw $t0, 132($sp)
  lw $t1, 128($sp)
  add $t0, $t0, $t1
  sw $t0, 132($sp)

                   # _t26 := _t26 + _t27
  lw $t0, 136($sp)
  lw $t1, 132($sp)
  add $t0, $t0, $t1
  sw $t0, 136($sp)

                   # _t26 := *_t26
  lw $t0, 136($sp)
  lw $t0, 0($t0)
  sw $t0, 136($sp)

                   # pivot := _t26
  lw $t0, 136($sp)
  sw $t0, 124($sp)

                   # _t30 := low
  lw $t0, 144($sp)
  sw $t0, 120($sp)

                   # _t31 := #1
  li $t0, 1
  sw $t0, 116($sp)

                   # _t29 := _t30 - _t31
  lw $t0, 120($sp)
  lw $t1, 116($sp)
  sub $t0, $t0, $t1
  sw $t0, 112($sp)

                   # pi := _t29
  lw $t0, 112($sp)
  sw $t0, 108($sp)

                   # _t32 := low
  lw $t0, 144($sp)
  sw $t0, 104($sp)

                   # pj := _t32
  lw $t0, 104($sp)
  sw $t0, 100($sp)

                   # LABEL _L4 :
_L4:

                   # _t33 := pj
  lw $t0, 100($sp)
  sw $t0, 96($sp)

                   # _t34 := high
  lw $t0, 140($sp)
  sw $t0, 92($sp)

                   #  _t34 GOTO _L5
  lw $t0, 96($sp)
  lw $t1, 92($sp)
  blt $t0, $t1, _L5

                   # GOTO _L6
  j _L6

                   # LABEL _L5 :
_L5:

                   # _t35 := parr
  lw $t0, 148($sp)
  sw $t0, 88($sp)

                   # _t37 := #0
  li $t0, 0
  sw $t0, 84($sp)

                   # _t38 := pj
  lw $t0, 100($sp)
  sw $t0, 80($sp)

                   # _t38 := _t38 * #4
  lw $t0, 80($sp)
  li $t1, 4
  mul $t0, $t0, $t1
  sw $t0, 80($sp)

                   # _t37 := _t37 + _t38
  lw $t0, 84($sp)
  lw $t1, 80($sp)
  add $t0, $t0, $t1
  sw $t0, 84($sp)

                   # _t35 := _t35 + _t37
  lw $t0, 88($sp)
  lw $t1, 84($sp)
  add $t0, $t0, $t1
  sw $t0, 88($sp)

                   # _t35 := *_t35
  lw $t0, 88($sp)
  lw $t0, 0($t0)
  sw $t0, 88($sp)

                   # _t36 := pivot
  lw $t0, 124($sp)
  sw $t0, 76($sp)

                   #  _t36 GOTO _L7
  lw $t0, 88($sp)
  lw $t1, 76($sp)
  blt $t0, $t1, _L7

                   # GOTO _L8
  j _L8

                   # LABEL _L7 :
_L7:

                   # _t40 := pi
  lw $t0, 108($sp)
  sw $t0, 72($sp)

                   # _t41 := #1
  li $t0, 1
  sw $t0, 68($sp)

                   # _t39 := _t40 + _t41
  lw $t0, 72($sp)
  lw $t1, 68($sp)
  add $t0, $t0, $t1
  sw $t0, 64($sp)

                   # pi := _t39
  lw $t0, 64($sp)
  sw $t0, 108($sp)

                   # _t42 := parr
  lw $t0, 148($sp)
  sw $t0, 60($sp)

                   # _t43 := pi
  lw $t0, 108($sp)
  sw $t0, 56($sp)

                   # _t44 := pj
  lw $t0, 100($sp)
  sw $t0, 52($sp)

                   # ARG _t44
  lw $t0, 52($sp)
  move $a2, $t0

                   # ARG _t43
  lw $t0, 56($sp)
  move $a1, $t0

                   # ARG _t42
  lw $t0, 60($sp)
  move $a0, $t0

                   # tNULL := CALL swap
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal swap
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 48($sp)

                   # LABEL _L8 :
_L8:

                   # _t46 := pj
  lw $t0, 100($sp)
  sw $t0, 40($sp)

                   # _t47 := #1
  li $t0, 1
  sw $t0, 36($sp)

                   # _t45 := _t46 + _t47
  lw $t0, 40($sp)
  lw $t1, 36($sp)
  add $t0, $t0, $t1
  sw $t0, 32($sp)

                   # pj := _t45
  lw $t0, 32($sp)
  sw $t0, 100($sp)

                   # GOTO _L4
  j _L4

                   # LABEL _L6 :
_L6:

                   # _t48 := parr
  lw $t0, 148($sp)
  sw $t0, 28($sp)

                   # _t50 := pi
  lw $t0, 108($sp)
  sw $t0, 24($sp)

                   # _t51 := #1
  li $t0, 1
  sw $t0, 20($sp)

                   # _t49 := _t50 + _t51
  lw $t0, 24($sp)
  lw $t1, 20($sp)
  add $t0, $t0, $t1
  sw $t0, 16($sp)

                   # _t52 := high
  lw $t0, 140($sp)
  sw $t0, 12($sp)

                   # ARG _t52
  lw $t0, 12($sp)
  move $a2, $t0

                   # ARG _t49
  lw $t0, 16($sp)
  move $a1, $t0

                   # ARG _t48
  lw $t0, 28($sp)
  move $a0, $t0

                   # tNULL := CALL swap
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal swap
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 48($sp)

                   # _t54 := pi
  lw $t0, 108($sp)
  sw $t0, 8($sp)

                   # _t55 := #1
  li $t0, 1
  sw $t0, 4($sp)

                   # _t53 := _t54 + _t55
  lw $t0, 8($sp)
  lw $t1, 4($sp)
  add $t0, $t0, $t1
  sw $t0, 0($sp)

                   # RETURN _t53
  lw $v0, 0($sp)
  move $sp, $s8
  lw $s8, -4($s8)
  jr $ra

                   # FUNCTION quickSort :
quickSort:
  addi $sp, $sp, -4
  sw $s8, 0($sp)
  la $s8, 4($sp)
  addi $sp, $sp, -96
# qarr -> 92($sp)
# l -> 88($sp)
# r -> 84($sp)
# _t56 -> 80($sp)
# _t57 -> 76($sp)
# _t59 -> 72($sp)
# _t60 -> 68($sp)
# _t61 -> 64($sp)
# _t58 -> 60($sp)
# partition -> 56($sp)
# pos -> 52($sp)
# _t62 -> 48($sp)
# _t63 -> 44($sp)
# _t65 -> 40($sp)
# _t66 -> 36($sp)
# _t64 -> 32($sp)
# tNULL -> 28($sp)
# quickSort -> 24($sp)
# _t67 -> 20($sp)
# _t69 -> 16($sp)
# _t70 -> 12($sp)
# _t68 -> 8($sp)
# _t71 -> 4($sp)
# _t72 -> 0($sp)

                   # PARAM qarr
  move $t0, $a0
  sw $t0, 92($sp)

                   # PARAM l
  move $t0, $a1
  sw $t0, 88($sp)

                   # PARAM r
  move $t0, $a2
  sw $t0, 84($sp)

                   # _t56 := l
  lw $t0, 88($sp)
  sw $t0, 80($sp)

                   # _t57 := r
  lw $t0, 84($sp)
  sw $t0, 76($sp)

                   #  _t57 GOTO _L9
  lw $t0, 80($sp)
  lw $t1, 76($sp)
  blt $t0, $t1, _L9

                   # GOTO _L10
  j _L10

                   # LABEL _L9 :
_L9:

                   # _t59 := qarr
  lw $t0, 92($sp)
  sw $t0, 72($sp)

                   # _t60 := l
  lw $t0, 88($sp)
  sw $t0, 68($sp)

                   # _t61 := r
  lw $t0, 84($sp)
  sw $t0, 64($sp)

                   # ARG _t61
  lw $t0, 64($sp)
  move $a2, $t0

                   # ARG _t60
  lw $t0, 68($sp)
  move $a1, $t0

                   # ARG _t59
  lw $t0, 72($sp)
  move $a0, $t0

                   # _t58 := CALL partition
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal partition
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 60($sp)

                   # pos := _t58
  lw $t0, 60($sp)
  sw $t0, 52($sp)

                   # _t62 := qarr
  lw $t0, 92($sp)
  sw $t0, 48($sp)

                   # _t63 := l
  lw $t0, 88($sp)
  sw $t0, 44($sp)

                   # _t65 := pos
  lw $t0, 52($sp)
  sw $t0, 40($sp)

                   # _t66 := #1
  li $t0, 1
  sw $t0, 36($sp)

                   # _t64 := _t65 - _t66
  lw $t0, 40($sp)
  lw $t1, 36($sp)
  sub $t0, $t0, $t1
  sw $t0, 32($sp)

                   # ARG _t64
  lw $t0, 32($sp)
  move $a2, $t0

                   # ARG _t63
  lw $t0, 44($sp)
  move $a1, $t0

                   # ARG _t62
  lw $t0, 48($sp)
  move $a0, $t0

                   # tNULL := CALL quickSort
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal quickSort
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 28($sp)

                   # _t67 := qarr
  lw $t0, 92($sp)
  sw $t0, 20($sp)

                   # _t69 := pos
  lw $t0, 52($sp)
  sw $t0, 16($sp)

                   # _t70 := #1
  li $t0, 1
  sw $t0, 12($sp)

                   # _t68 := _t69 + _t70
  lw $t0, 16($sp)
  lw $t1, 12($sp)
  add $t0, $t0, $t1
  sw $t0, 8($sp)

                   # _t71 := r
  lw $t0, 84($sp)
  sw $t0, 4($sp)

                   # ARG _t71
  lw $t0, 4($sp)
  move $a2, $t0

                   # ARG _t68
  lw $t0, 8($sp)
  move $a1, $t0

                   # ARG _t67
  lw $t0, 20($sp)
  move $a0, $t0

                   # tNULL := CALL quickSort
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal quickSort
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 28($sp)

                   # LABEL _L10 :
_L10:

                   # _t72 := #0
  li $t0, 0
  sw $t0, 0($sp)

                   # RETURN _t72
  lw $v0, 0($sp)
  move $sp, $s8
  lw $s8, -4($s8)
  jr $ra

                   # FUNCTION main :
main:
  addi $sp, $sp, -4
  sw $s8, 0($sp)
  la $s8, 4($sp)
  addi $sp, $sp, -4088
# arr -> 88($sp)
# _t73 -> 84($sp)
# i -> 80($sp)
# _t74 -> 76($sp)
# n -> 72($sp)
# _t75 -> 68($sp)
# _t76 -> 64($sp)
# _t77 -> 60($sp)
# _t78 -> 56($sp)
# _t79 -> 52($sp)
# _t80 -> 48($sp)
# tNULL -> 44($sp)
# _t82 -> 40($sp)
# _t83 -> 36($sp)
# _t81 -> 32($sp)
# _t84 -> 28($sp)
# _t85 -> 24($sp)
# _t86 -> 20($sp)
# quickSort -> 16($sp)
# _t87 -> 12($sp)
# _t88 -> 8($sp)
# Output -> 4($sp)
# _t89 -> 0($sp)

                   # DEC arr 4000

                   # _t73 := #1
  li $t0, 1
  sw $t0, 84($sp)

                   # i := _t73
  lw $t0, 84($sp)
  sw $t0, 80($sp)

                   # READ _t74
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 76($sp)

                   # n := _t74
  lw $t0, 76($sp)
  sw $t0, 72($sp)

                   # LABEL _L11 :
_L11:

                   # _t75 := i
  lw $t0, 80($sp)
  sw $t0, 68($sp)

                   # _t76 := n
  lw $t0, 72($sp)
  sw $t0, 64($sp)

                   #  _t76 GOTO _L12
  lw $t0, 68($sp)
  lw $t1, 64($sp)
  ble $t0, $t1, _L12

                   # GOTO _L13
  j _L13

                   # LABEL _L12 :
_L12:

                   # READ _t77
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 60($sp)

                   # _t78 := #0
  li $t0, 0
  sw $t0, 56($sp)

                   # _t79 := i
  lw $t0, 80($sp)
  sw $t0, 52($sp)

                   # _t79 := _t79 * #4
  lw $t0, 52($sp)
  li $t1, 4
  mul $t0, $t0, $t1
  sw $t0, 52($sp)

                   # _t78 := _t78 + _t79
  lw $t0, 56($sp)
  lw $t1, 52($sp)
  add $t0, $t0, $t1
  sw $t0, 56($sp)

                   # _t80 := &arr
  la $t0, 88($sp)
  sw $t0, 48($sp)

                   # _t80 := _t80 + _t78
  lw $t0, 48($sp)
  lw $t1, 56($sp)
  add $t0, $t0, $t1
  sw $t0, 48($sp)

                   # *_t80 := _t77
  lw $t0, 48($sp)
  lw $t1, 60($sp)
  sw $t1, 0($t0)

                   # tNULL := _t77
  lw $t0, 60($sp)
  sw $t0, 44($sp)

                   # _t82 := i
  lw $t0, 80($sp)
  sw $t0, 40($sp)

                   # _t83 := #1
  li $t0, 1
  sw $t0, 36($sp)

                   # _t81 := _t82 + _t83
  lw $t0, 40($sp)
  lw $t1, 36($sp)
  add $t0, $t0, $t1
  sw $t0, 32($sp)

                   # i := _t81
  lw $t0, 32($sp)
  sw $t0, 80($sp)

                   # GOTO _L11
  j _L11

                   # LABEL _L13 :
_L13:

                   # _t84 := &arr
  la $t0, 88($sp)
  sw $t0, 28($sp)

                   # _t85 := #1
  li $t0, 1
  sw $t0, 24($sp)

                   # _t86 := n
  lw $t0, 72($sp)
  sw $t0, 20($sp)

                   # ARG _t86
  lw $t0, 20($sp)
  move $a2, $t0

                   # ARG _t85
  lw $t0, 24($sp)
  move $a1, $t0

                   # ARG _t84
  lw $t0, 28($sp)
  move $a0, $t0

                   # tNULL := CALL quickSort
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal quickSort
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 44($sp)

                   # _t87 := &arr
  la $t0, 88($sp)
  sw $t0, 12($sp)

                   # _t88 := n
  lw $t0, 72($sp)
  sw $t0, 8($sp)

                   # ARG _t88
  lw $t0, 8($sp)
  move $a1, $t0

                   # ARG _t87
  lw $t0, 12($sp)
  move $a0, $t0

                   # tNULL := CALL Output
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal Output
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 44($sp)

                   # _t89 := #0
  li $t0, 0
  sw $t0, 0($sp)

                   # RETURN _t89
  lw $v0, 0($sp)
  move $sp, $s8
  lw $s8, -4($s8)
  jr $ra
