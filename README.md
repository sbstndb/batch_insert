# Batch Insert in a Sorted std::vector

## Description

This project implements two different strategies for inserting a batch of values into a sorted `std::vector` while maintaining the sorted order.

### Implementations

1. **Naive Version** (`naive_batch_insert`)
   - Sequential value insertion
   - Complexity: O(n * m)
   - Simple to understand
   - Less performant for large sets

2. **Optimized Version** (`optimized_batch_insert`)
   - Merging two sorted vectors
   - Complexity: O(n + m log m)
   - Minimizes reallocations
   - Eliminates duplicates

## Features

- Generic template implementation
- Duplicate handling
- Preserves sorted order
- Comparative benchmarks
- Comprehensive unit tests

## Prerequisites

- C++17 compiler
- CMake 3.10+
- Google Test
- Google Benchmark

## Installation

```bash
git clone https://github.com/your_username/batch_insert.git
cd batch_insert
mkdir build && cd build
cmake ..
make
```

## Usage

```cpp
#include "batch_insert.h"

std::vector<int> vec = {1, 3, 5};
std::vector<int> values = {2, 4, 6};

// Naive insertion
batch_insert::naive_batch_insert(vec, values);

// Optimized insertion
batch_insert::optimized_batch_insert(vec, values);
```

## Benchmarks

Benchmarks compare the performance of both implementations for different vector sizes.

### Typical Results

| Vector Size | Naive | Optimized |
|------------|-------|-----------|
| 100 elements | 10 µs | 12 µs     |
| 1000 elements| 28 µs | 40 µs     |
| 10000 elements| 240 µs| 355 µs    |

## Tests

The project includes unit tests covering various scenarios:
- Empty vector
- Insertions with duplicates
- Insertions without new values
- Large insertions

## Contributing

Contributions are welcome! Please submit a pull request.

## License

[Specify your license]

## Author

[Your Name] 