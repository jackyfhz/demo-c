CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main
SRCS = main.c utils.c demo_sizeof.c demo_pointer_int.c demo_pointer_array_int.c demo_pointer_structure.c
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)