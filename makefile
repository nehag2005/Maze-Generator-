CC = gcc
CFLAGS = -Wall -Wextra -std=c99


SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

maze: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f mazegen $(OBJS)