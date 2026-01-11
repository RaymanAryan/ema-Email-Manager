# Makefile to make the build fast and easy
# Compiler (compatible with -I option)
CC = gcc

# Directories
BUILD = build
BIN = bin
SRC = src
INC = include

# Install prefix (Termux + Linux safe)
PREFIX ?= $(HOME)/.local
BINDIR = $(PREFIX)/bin

TARGET = $(BIN)/ema

# Object files
OBJS = \
	$(BUILD)/main.o \
	$(BUILD)/contactor.o \
	$(BUILD)/manager.o \
	$(BUILD)/emails.o \
	$(BUILD)/names.o \
	$(BUILD)/memory.o \
	$(BUILD)/user.o

# Default target
all: run

# Link
run: $(OBJS)
	mkdir -p $(BIN)
	$(CC) -I$(INC) $(OBJS) -o $(TARGET)

# Compile rules
$(BUILD)/main.o: $(SRC)/main.c
	mkdir -p $(BUILD)
	$(CC) -I$(INC) -c $(SRC)/main.c -o $(BUILD)/main.o

$(BUILD)/contactor.o: $(SRC)/contactor.c $(INC)/contactor.h
	mkdir -p $(BUILD)
	$(CC) -I$(INC) -c $(SRC)/contactor.c -o $(BUILD)/contactor.o

$(BUILD)/manager.o: $(SRC)/manager.c $(INC)/manager.h
	mkdir -p $(BUILD)
	$(CC) -I$(INC) -c $(SRC)/manager.c -o $(BUILD)/manager.o

$(BUILD)/emails.o: $(SRC)/emails.c $(INC)/emails.h
	mkdir -p $(BUILD)
	$(CC) -I$(INC) -c $(SRC)/emails.c -o $(BUILD)/emails.o

$(BUILD)/names.o: $(SRC)/names.c $(INC)/names.h
	mkdir -p $(BUILD)
	$(CC) -I$(INC) -c $(SRC)/names.c -o $(BUILD)/names.o

$(BUILD)/memory.o: $(SRC)/memory.c $(INC)/memory.h
	mkdir -p $(BUILD)
	$(CC) -I$(INC) -c $(SRC)/memory.c -o $(BUILD)/memory.o

$(BUILD)/user.o: $(SRC)/user.c $(INC)/user.h
	mkdir -p $(BUILD)
	$(CC) -I$(INC) -c $(SRC)/user.c -o $(BUILD)/user.o

# Install target
install: run
	mkdir -p $(BINDIR)
	cp $(TARGET) $(BINDIR)
	@echo "Installed to $(BINDIR)/app"

# Uninstall target
uninstall:
	rm -f $(BINDIR)/app
	@echo "Removed $(BINDIR)/app"

# Clean (DO NOT delete user saves)
clean:
	rm -f $(BUILD)/* $(BIN)/*