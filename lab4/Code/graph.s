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

                   # FUNCTION main :
main:
  addi $sp, $sp, -4
  sw $s8, 0($sp)
  la $s8, 4($sp)
  addi $sp, $sp, -10164
# g -> 164($sp)
# _t1 -> 160($sp)
# n -> 156($sp)
# _t2 -> 152($sp)
# m -> 148($sp)
# _t3 -> 144($sp)
# i -> 140($sp)
# _t4 -> 136($sp)
# _t5 -> 132($sp)
# _t6 -> 128($sp)
# j -> 124($sp)
# _t7 -> 120($sp)
# _t8 -> 116($sp)
# _t9 -> 112($sp)
# _t10 -> 108($sp)
# _t11 -> 104($sp)
# _t12 -> 100($sp)
# _t13 -> 96($sp)
# tNULL -> 92($sp)
# _t15 -> 88($sp)
# _t16 -> 84($sp)
# _t14 -> 80($sp)
# _t18 -> 76($sp)
# _t19 -> 72($sp)
# _t17 -> 68($sp)
# _t20 -> 64($sp)
# _t21 -> 60($sp)
# _t22 -> 56($sp)
# _t23 -> 52($sp)
# _t24 -> 48($sp)
# _t25 -> 44($sp)
# _t26 -> 40($sp)
# _t27 -> 36($sp)
# _t28 -> 32($sp)
# _t29 -> 28($sp)
# _t31 -> 24($sp)
# _t32 -> 20($sp)
# _t30 -> 16($sp)
# _t34 -> 12($sp)
# _t35 -> 8($sp)
# _t33 -> 4($sp)
# _t36 -> 0($sp)

                   # DEC g 10000

                   # READ _t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 160($sp)

                   # n := _t1
  lw $t0, 160($sp)
  sw $t0, 156($sp)

                   # READ _t2
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 152($sp)

                   # m := _t2
  lw $t0, 152($sp)
  sw $t0, 148($sp)

                   # _t3 := #1
  li $t0, 1
  sw $t0, 144($sp)

                   # i := _t3
  lw $t0, 144($sp)
  sw $t0, 140($sp)

                   # LABEL _L1 :
_L1:

                   # _t4 := i
  lw $t0, 140($sp)
  sw $t0, 136($sp)

                   # _t5 := n
  lw $t0, 156($sp)
  sw $t0, 132($sp)

                   #  _t5 GOTO _L2
  lw $t0, 136($sp)
  lw $t1, 132($sp)
  ble $t0, $t1, _L2

                   # GOTO _L3
  j _L3

                   # LABEL _L2 :
_L2:

                   # _t6 := #1
  li $t0, 1
  sw $t0, 128($sp)

                   # j := _t6
  lw $t0, 128($sp)
  sw $t0, 124($sp)

                   # LABEL _L4 :
_L4:

                   # _t7 := j
  lw $t0, 124($sp)
  sw $t0, 120($sp)

                   # _t8 := m
  lw $t0, 148($sp)
  sw $t0, 116($sp)

                   #  _t8 GOTO _L5
  lw $t0, 120($sp)
  lw $t1, 116($sp)
  ble $t0, $t1, _L5

                   # GOTO _L6
  j _L6

                   # LABEL _L5 :
_L5:

                   # READ _t9
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 112($sp)

                   # _t10 := #0
  li $t0, 0
  sw $t0, 108($sp)

                   # _t11 := i
  lw $t0, 140($sp)
  sw $t0, 104($sp)

                   # _t11 := _t11 * #200
  lw $t0, 104($sp)
  li $t1, 200
  mul $t0, $t0, $t1
  sw $t0, 104($sp)

                   # _t10 := _t10 + _t11
  lw $t0, 108($sp)
  lw $t1, 104($sp)
  add $t0, $t0, $t1
  sw $t0, 108($sp)

                   # _t12 := j
  lw $t0, 124($sp)
  sw $t0, 100($sp)

                   # _t12 := _t12 * #4
  lw $t0, 100($sp)
  li $t1, 4
  mul $t0, $t0, $t1
  sw $t0, 100($sp)

                   # _t10 := _t10 + _t12
  lw $t0, 108($sp)
  lw $t1, 100($sp)
  add $t0, $t0, $t1
  sw $t0, 108($sp)

                   # _t13 := &g
  la $t0, 164($sp)
  sw $t0, 96($sp)

                   # _t13 := _t13 + _t10
  lw $t0, 96($sp)
  lw $t1, 108($sp)
  add $t0, $t0, $t1
  sw $t0, 96($sp)

                   # *_t13 := _t9
  lw $t0, 96($sp)
  lw $t1, 112($sp)
  sw $t1, 0($t0)

                   # tNULL := _t9
  lw $t0, 112($sp)
  sw $t0, 92($sp)

                   # _t15 := j
  lw $t0, 124($sp)
  sw $t0, 88($sp)

                   # _t16 := #1
  li $t0, 1
  sw $t0, 84($sp)

                   # _t14 := _t15 + _t16
  lw $t0, 88($sp)
  lw $t1, 84($sp)
  add $t0, $t0, $t1
  sw $t0, 80($sp)

                   # j := _t14
  lw $t0, 80($sp)
  sw $t0, 124($sp)

                   # GOTO _L4
  j _L4

                   # LABEL _L6 :
_L6:

                   # _t18 := i
  lw $t0, 140($sp)
  sw $t0, 76($sp)

                   # _t19 := #1
  li $t0, 1
  sw $t0, 72($sp)

                   # _t17 := _t18 + _t19
  lw $t0, 76($sp)
  lw $t1, 72($sp)
  add $t0, $t0, $t1
  sw $t0, 68($sp)

                   # i := _t17
  lw $t0, 68($sp)
  sw $t0, 140($sp)

                   # GOTO _L1
  j _L1

                   # LABEL _L3 :
_L3:

                   # _t20 := #1
  li $t0, 1
  sw $t0, 64($sp)

                   # i := _t20
  lw $t0, 64($sp)
  sw $t0, 140($sp)

                   # LABEL _L7 :
_L7:

                   # _t21 := i
  lw $t0, 140($sp)
  sw $t0, 60($sp)

                   # _t22 := m
  lw $t0, 148($sp)
  sw $t0, 56($sp)

                   #  _t22 GOTO _L8
  lw $t0, 60($sp)
  lw $t1, 56($sp)
  ble $t0, $t1, _L8

                   # GOTO _L9
  j _L9

                   # LABEL _L8 :
_L8:

                   # _t23 := #1
  li $t0, 1
  sw $t0, 52($sp)

                   # j := _t23
  lw $t0, 52($sp)
  sw $t0, 124($sp)

                   # LABEL _L10 :
_L10:

                   # _t24 := j
  lw $t0, 124($sp)
  sw $t0, 48($sp)

                   # _t25 := n
  lw $t0, 156($sp)
  sw $t0, 44($sp)

                   #  _t25 GOTO _L11
  lw $t0, 48($sp)
  lw $t1, 44($sp)
  ble $t0, $t1, _L11

                   # GOTO _L12
  j _L12

                   # LABEL _L11 :
_L11:

                   # _t26 := &g
  la $t0, 164($sp)
  sw $t0, 40($sp)

                   # _t27 := #0
  li $t0, 0
  sw $t0, 36($sp)

                   # _t28 := j
  lw $t0, 124($sp)
  sw $t0, 32($sp)

                   # _t28 := _t28 * #200
  lw $t0, 32($sp)
  li $t1, 200
  mul $t0, $t0, $t1
  sw $t0, 32($sp)

                   # _t27 := _t27 + _t28
  lw $t0, 36($sp)
  lw $t1, 32($sp)
  add $t0, $t0, $t1
  sw $t0, 36($sp)

                   # _t29 := i
  lw $t0, 140($sp)
  sw $t0, 28($sp)

                   # _t29 := _t29 * #4
  lw $t0, 28($sp)
  li $t1, 4
  mul $t0, $t0, $t1
  sw $t0, 28($sp)

                   # _t27 := _t27 + _t29
  lw $t0, 36($sp)
  lw $t1, 28($sp)
  add $t0, $t0, $t1
  sw $t0, 36($sp)

                   # _t26 := _t26 + _t27
  lw $t0, 40($sp)
  lw $t1, 36($sp)
  add $t0, $t0, $t1
  sw $t0, 40($sp)

                   # _t26 := *_t26
  lw $t0, 40($sp)
  lw $t0, 0($t0)
  sw $t0, 40($sp)

                   # WRITE _t26
  lw $a0, 40($sp)
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0

                   # tNULL := #0
  li $t0, 0
  sw $t0, 92($sp)

                   # _t31 := j
  lw $t0, 124($sp)
  sw $t0, 24($sp)

                   # _t32 := #1
  li $t0, 1
  sw $t0, 20($sp)

                   # _t30 := _t31 + _t32
  lw $t0, 24($sp)
  lw $t1, 20($sp)
  add $t0, $t0, $t1
  sw $t0, 16($sp)

                   # j := _t30
  lw $t0, 16($sp)
  sw $t0, 124($sp)

                   # GOTO _L10
  j _L10

                   # LABEL _L12 :
_L12:

                   # _t34 := i
  lw $t0, 140($sp)
  sw $t0, 12($sp)

                   # _t35 := #1
  li $t0, 1
  sw $t0, 8($sp)

                   # _t33 := _t34 + _t35
  lw $t0, 12($sp)
  lw $t1, 8($sp)
  add $t0, $t0, $t1
  sw $t0, 4($sp)

                   # i := _t33
  lw $t0, 4($sp)
  sw $t0, 140($sp)

                   # GOTO _L7
  j _L7

                   # LABEL _L9 :
_L9:

                   # _t36 := #0
  li $t0, 0
  sw $t0, 0($sp)

                   # RETURN _t36
  lw $v0, 0($sp)
  move $sp, $s8
  lw $s8, -4($s8)
  jr $ra
