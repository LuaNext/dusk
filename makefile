TARGET_EXEC ?= dusk

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := main.c scanner.c runtime/vm.c runtime/jit.c
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := ${SRC_DIRS}/include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CC = gcc
CFLAGS = -Wall -O2

build/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@find ./build ! -name 'dusk' -type f -exec rm -f {} +
	@rm -rf ./build/runtime

build/%.c.o: src/%.c
	mkdir -p ./build/runtime
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	find ./build ! -name 'dusk' -type f -exec rm -f {} +
	rm -rf ./build/runtime

run:
	make
	cls
	./build/${TARGET_EXEC}

-include $(DEPS)

MKDIR_P ?= mkdir -p