# Variables
CC = gcc
CFLAGS = -Wall -g
BUILD_DIR = build
SCRIPTS_DIR = scripts
SRC_DIR = src
DOC_DIR = documentation
DOCS_SUBDIR = docs
DOXYFILE = Doxyfile

# Default target
all: $(BUILD_DIR)/main docs

# Create required directories
$(BUILD_DIR) $(DOC_DIR) $(DOC_DIR)/$(DOCS_SUBDIR):
	mkdir -p $@

# Compile rules
$(BUILD_DIR)/main: $(SRC_DIR)/main.c $(BUILD_DIR)/student.o $(BUILD_DIR)/course.o | $(BUILD_DIR) $(DOC_DIR) $(DOC_DIR)/$(DOCS_SUBDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/student.o: $(SRC_DIR)/student.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/course.o: $(SRC_DIR)/course.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Doxygen rules
$(DOXYFILE):
	doxygen -g

.PHONY: docs
docs: $(DOXYFILE)
	doxygen $(DOXYFILE)

