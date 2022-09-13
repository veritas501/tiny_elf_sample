# Tiny ELF sample

## pop_shell_x64

- arch: x64
- shellcode pos: 0x78
- size: 180 bytes

just pop a shell.

test:

```
./pop_shell_x64
$ whoami
veritas
$
```



## pop_shell_preload_x64.so

- arch: x64
- shellcode pos: 0x170
- size: 428 bytes

just pop a shell, but can be used to hijack program using LD_PRELOAD or dlopen.

test:

```
./pop_shell_preload_x64.so
$ whoami
veritas
$

LD_PRELOAD=./pop_shell_preload_x64.so /usr/bin/true
$ whoami
veritas
$
```



## pop_shell_alnum_x64

- arch: x64
- size: 323 bytes

just pop a shell, but shellcode is alphanumeric encoded by [AE64](https://github.com/veritas501/ae64).

```
$ hexdump -C pop_shell_alnum_x64
00000000  7f 45 4c 46 02 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
00000010  03 00 3e 00 01 00 00 00  28 00 00 00 00 00 00 00  |..>.....(.......|
00000020  40 00 00 00 00 00 00 00  e8 00 00 00 00 58 eb 48  |@............X.H|
00000030  00 00 00 00 40 00 38 00  01 00 40 00 00 00 01 00  |....@.8...@.....|
00000040  01 00 00 00 07 00 00 00  00 00 00 00 00 00 00 00  |................|
00000050  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000060  78 00 00 00 00 00 00 00  78 00 00 00 00 00 00 00  |x.......x.......|
00000070  00 10 00 00 00 00 00 00  57 54 59 48 33 39 59 6a  |........WTYH39Yj|
00000080  6f 54 59 66 69 39 70 59  57 5a 6a 4a 54 59 66 69  |oTYfi9pYWZjJTYfi|
00000090  39 70 30 30 74 38 30 30  54 38 55 30 54 38 56 6a  |9p00t800T8U0T8Vj|
000000a0  42 54 59 66 69 39 38 59  30 74 38 30 30 54 38 4b  |BTYfi98Y0t800T8K|
000000b0  48 63 31 6a 4b 54 59 66  69 31 56 55 4c 4a 74 30  |Hc1jKTYfi1VULJt0|
000000c0  59 6a 32 54 59 66 69 31  67 66 56 59 49 4a 34 4e  |Yj2TYfi1gfVYIJ4N|
000000d0  56 54 58 41 6b 76 32 31  42 32 74 31 31 41 30 76  |VTXAkv21B2t11A0v|
000000e0  31 49 6f 56 4c 39 30 75  7a 51 79 52 5a 45 45 6e  |1IoVL90uzQyRZEEn|
000000f0  64 65 65 35 64 46 52 4a  4f 41 4f 64 75 41 35 54  |dee5dFRJOAOduA5T|
00000100  59 6f 6b 54 52 63 31 30  73 69 6e 71 4a 4b 30 31  |YokTRc10sinqJK01|
00000110  41 41 4a 4c 56 36 56 31  45 73 6d 65 69 6c 62 30  |AAJLV6V1Esmeilb0|
00000120  37 6f 46 6a 73 5a 6b 66  4e 6f 35 7a 50 41 31 5a  |7oFjsZkfNo5zPA1Z|
00000130  30 6c 6a 48 69 4c 47 48  6e 34 4c 48 63 65 62 32  |0ljHiLGHn4LHceb2|
00000140  54 66 4c                                          |TfL|
00000143
```



test:

```
./pop_shell_alnum_x64
$ whoami
veritas
$
```

