# Advent of Code - C Solutions

## Structure

```
c-aoc/
├── Makefile
├── common/
│   ├── utils.h          # Utility function declarations
│   └── utils.c          # Shared helpers (file I/O, parsing)
└── YEAR/
    └── dayXX/
        ├── main.c       # Entry point, calls part1 & part2
        ├── part1.c      # Part 1 solution
        ├── part1.h      # Part 1 function declaration
        ├── part2.c      # Part 2 solution
        ├── part2.h      # Part 2 function declaration
        └── input.txt    # Puzzle input
```

## Usage

### Run a specific day:
```bash
make run DAY=2015/day01
```

### Build all days in a year:
```bash
make year YEAR=2015
```

### Clean executables:
```bash
make clean
```

### Show help:
```bash
make
```

## Adding a New Day

1. Copy the `2015/day01` directory structure
2. Update `part1.c` and `part2.c` with your solution
3. Add your puzzle input to `input.txt`
4. Run with `make run DAY=YEAR/dayXX`

## Common Utilities

- `read_file(filename)` - Read entire file as string (remember to `free()`)
- `read_lines(filename, &count)` - Read file as array of lines
