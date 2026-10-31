CC = aarch64-none-elf-gcc
LD = aarch64-none-elf-ld
OBJCOPY = aarch64-none-elf-objcopy

CFLAGS = -Wall -O2 -ffreestanding -nostdlib -nostinc -fno-builtin
LDFLAGS = -T linker.ld --nostdlib

SRCS = entry.s uart.c main.c
OBJS = $(SRCS:.c=.o)
OBJS := $(OBJS:.s=.o)

all: corestrap.bin

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

corestrap.elf: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o corestrap.elf

corestrap.bin: corestrap.elf
	$(OBJCOPY) -O binary corestrap.elf corestrap.bin

clean:
	rm -f *.o corestrap.elf corestrap.bin
