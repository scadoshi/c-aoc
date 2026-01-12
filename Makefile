CC = gcc
CFLAGS = -Wall -Wextra -g -I./common

# Find all .c files in common/ recursively
COMMON_SOURCES = $(shell find common -name '*.c')

# Default target shows help
.DEFAULT_GOAL := help

# Build and run a specific day
# Usage: make run DAY=2015/day01
.PHONY: run
run:
	@echo "Building $(DAY)..."
	@$(CC) $(CFLAGS) -I./$(DAY) $(COMMON_SOURCES) $(DAY)/main.c $(DAY)/part1.c $(DAY)/part2.c -o $(DAY)/solution
	@echo "Running $(DAY)..."
	@$(DAY)/solution

# Build all days in a year
# Usage: make year YEAR=2015
.PHONY: year
year:
	@for day in $(YEAR)/day*/main.c; do \
		dir=$$(dirname $$day); \
		echo "Building $$dir..."; \
		$(CC) $(CFLAGS) -I./$$dir $(COMMON_SOURCES) $$dir/main.c $$dir/part1.c $$dir/part2.c -o $$dir/solution; \
	done

# Clean all executables
.PHONY: clean
clean:
	@echo "Cleaning executables..."
	@find . -type f -name "solution" -delete
	@echo "Done!"

# Help message
.PHONY: help
help:
	@echo "Advent of Code - C Solutions"
	@echo ""
	@echo "Usage:"
	@echo "  make run DAY=2015/day01    Build and run a specific day"
	@echo "  make year YEAR=2015        Build all days in a year"
	@echo "  make clean                 Remove all executables"
