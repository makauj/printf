CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -I.
SRC = _printf.c flush_buffer.c format_handler.c handle_binary.c handle_char.c handle_custom_string.c handle_hex.c handle_integer.c handle_octal.c handle_pointer.c handle_string.c handle_unsigned.c handle_unknown.c my_itoa.c my_ftoa.c
OBJ = $(SRC:.c=.o)
TEST_SRC = tests/test_runner.c
TARGET = libprintf.a
TEST_TARGET = test_runner

ifeq ($(OS),Windows_NT)
TEST_BIN = $(TEST_TARGET).exe
RUN_TEST = .\\$(TEST_BIN)
CLEAN_CMD = powershell -NoProfile -Command "$$ErrorActionPreference='SilentlyContinue'; Remove-Item -Force $(OBJ) $(TARGET) $(TEST_BIN)"
else
TEST_BIN = $(TEST_TARGET)
RUN_TEST = ./$(TEST_BIN)
CLEAN_CMD = rm -f $(OBJ) $(TARGET) $(TEST_BIN)
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $^

test: $(TARGET) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) tests/test_printf.c -L. -lprintf -o $(TEST_BIN)
	$(RUN_TEST)

clean:
	$(CLEAN_CMD)

.PHONY: all clean test
