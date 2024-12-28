;;data section
section .data
  ;;msg variable 
  msg db  "hello, world!"


;; text section
section .text
  ;; reference to program entry point
  global _start

;; Entry point
_start:
  ;; specify the number of the sys call (1 == sys_write)
  mov   rax, 1
  ;; first argument of sys_write (1 == stdout)
  mov  rdi, 1
  ;; second argument of sys_write
  mov   rsi, msg
  ;;third argument of sys_write (len of msg)
  mov   rdx, 13

  ;;syscall sys_write
  syscall
  ;;specify number sys call (60 == sys_exit)
  mov   rax, 60
  ;; first argument of sys_exit ( == exit_code)
  mov  rdi, 0
  ;; call sys_exit
  syscall
