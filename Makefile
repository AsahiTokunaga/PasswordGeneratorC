TARGET = pwgenC
SRCS   = main.c \
	generate.c \
	getpool.c \
	getrand.c
OBJS   = $(SRCS:.c=.o)
INCL   = -Igenerate.h \
	-Igetpool.h \
	-Igetrand.h
CC     = gcc
CFLAGS = -Wall -Wextra -Werror -O2 -mrdrnd

all: $(TARGET) clean

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)

%.o: %.c $(INCL)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

clean:
	rm $(OBJS)
