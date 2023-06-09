#pragma once

#include <stddef.h>
#include <sys/syscall.h>

#define _syscall_do(sys_nbr, rettype)                                     \
    {                                                                     \
        register long r10 asm("r10") = (long)a4;                          \
        register long r8 asm("r8") = (long)a5;                            \
        register long r9 asm("r9") = (long)a6;                            \
        rettype ret;                                                      \
        asm volatile("syscall"                                            \
                     : "=a"(ret)                                          \
                     : "0"(sys_nbr), "D"(a1), "S"(a2), "d"(a3), "r"(r10), \
                       "r"(r8), "r"(r9)                                   \
                     : "cc", "rcx", "r11", "memory");                     \
        return ret;                                                       \
    }

#define _syscall6(sys_nbr, sys_name, rettype, t1, t2, t3, t4, t5, t6)          \
    static inline rettype sys_name(t1 a1, t2 a2, t3 a3, t4 a4, t5 a5, t6 a6) { \
        _syscall_do(sys_nbr, rettype)                                          \
    }

#define _syscall5(sys_nbr, sys_name, rettype, t1, t2, t3, t4, t5)       \
    static inline rettype sys_name(t1 a1, t2 a2, t3 a3, t4 a4, t5 a5) { \
        long a6;                                                        \
        _syscall_do(sys_nbr, rettype)                                   \
    }

#define _syscall4(sys_nbr, sys_name, rettype, t1, t2, t3, t4)    \
    static inline rettype sys_name(t1 a1, t2 a2, t3 a3, t4 a4) { \
        long a6, a5;                                             \
        _syscall_do(sys_nbr, rettype)                            \
    }

#define _syscall3(sys_nbr, sys_name, rettype, t1, t2, t3) \
    static inline rettype sys_name(t1 a1, t2 a2, t3 a3) { \
        long a6, a5, a4;                                  \
        _syscall_do(sys_nbr, rettype)                     \
    }

#define _syscall2(sys_nbr, sys_name, rettype, t1, t2) \
    static inline rettype sys_name(t1 a1, t2 a2) {    \
        long a6, a5, a4, a3;                          \
        _syscall_do(sys_nbr, rettype)                 \
    }

#define _syscall1(sys_nbr, sys_name, rettype, t1) \
    static inline rettype sys_name(t1 a1) {       \
        long a6, a5, a4, a3, a2;                  \
        _syscall_do(sys_nbr, rettype)             \
    }

#define _syscall0(sys_nbr, sys_name, rettype) \
    static inline rettype sys_name(void) {    \
        long a6, a5, a4, a3, a2, a1;          \
        _syscall_do(sys_nbr, rettype)         \
    }

_syscall1(SYS_exit, sys_exit, long, int);
_syscall3(SYS_setresuid, sys_setresuid, long, int, int, int);
_syscall3(SYS_setresgid, sys_setresgid, long, int, int, int);
_syscall3(SYS_execve, sys_execve, long, const char *, char **, char **);
_syscall3(SYS_write, sys_write, long, int, const char *, size_t);
_syscall3(SYS_open, sys_open, long, const char *, int, long);
_syscall1(SYS_close, sys_close, long, int);

#define O_RDONLY 00
#define O_WRONLY 01
#define O_RDWR 02