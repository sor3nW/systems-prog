CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = assign4.c
OBJS = $(SRCS:.c=.o)
EXEC = myprogram

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXEC) $(OBJS)
