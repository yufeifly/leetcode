SRC_DIR := src
BUILD_DIR := build

CFLAGS := -Wall -g -std=c++11

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS=$(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%)


all : prepare $(OBJS)

prepare:
	$(if $(wildcard $(BUILD_DIR)),,mkdir -p $(BUILD_DIR))

$(BUILD_DIR)/% : $(SRC_DIR)/%.cpp
	g++ $(CFLAGS) -o $@ $<

.PHONY = clean
clean:
	rm -rf $(OBJS)
