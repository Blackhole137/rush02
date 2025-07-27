.PHONY : all test fclean clean

CC        := /usr/bin/clang
CFLAGS    := -Wall -Wextra -Werror -I./includes

BUILD_DIR       := build
TEST_DIR        := tests

TARGET          := $(BUILD_DIR)/rush-02
TEST_TARGET     := $(BUILD_DIR)/tester

LIB_SOURCES     := $(wildcard src/lib/*.c)
LIB_OBJS        := $(addprefix $(BUILD_DIR),$(LIB_SOURCES:.c=.o))

MAIN_SOURCES    := $(wildcard src/*.c)
MAIN_OBJS       := $(addprefix $(BUILD_DIR)/,$(MAIN_SOURCES:.c=.o))

ALL_SOURCES    := $(MAIN_SOURCES) $(LIB_SOURCES)
ALL_OBJS       := $(MAIN_OBJS) $(LIB_OBJS)

all: $(TARGET)
$(TARGET): $(MAIN_OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $^

$(LIB_OBJS): $(LIB_SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJS): $(MAIN_SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

ft_getline_test: tests/ft_getline_test.c $(MAIN_OBJS) 
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $^

$(BUILD_DIR)/ft_getline.o: src/lib/rushgetline.c
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/$@ $^

fclean: clean
	rm -f $(TARGET) $(TEST_TARGET)

clean:
	find . -name '*.o' -print -delete
