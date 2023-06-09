.PHONY: binary clean

ifeq ($(CC),clang)
CFLAGS ?= -nostdlib -fpic
OPTI_LEVEL = -Oz
else
CFLAGS ?= -nostdlib -shared -fpic -pie
OPTI_LEVEL = -Os
endif
OPTI_FLAGS := $(OPTI_LEVEL) -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables -fcf-protection=none -mno-sse

binary: suid_shell
	chmod 755 $<

clean:
	rm -f *.s *.o

s.s: suid_shell.c
	$(CC) $< -masm=intel -S -o $@ $(CFLAGS) $(OPTI_FLAGS)
	sed -i '/.addrsig/d' $@
	sed -i '/.section/d' $@
	sed -i '/.p2align/d' $@

s.o: s.s
	as --64 -o $@ $<

suid_shell: s.o
	ld --oformat binary --omagic -o $@ $<
