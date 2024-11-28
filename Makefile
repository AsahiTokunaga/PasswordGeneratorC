TARGET = pwgenC
SRCS   = main.c
OBJS   = $(SRCS:.c=.o)
CC     = gcc
CFLAGS = -Wall -O2

all: $(TARGET) clean

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) -o $(OBJS)

clean:
	rm $(OBJS)
