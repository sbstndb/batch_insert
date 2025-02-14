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
- Unit tests

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

### Detailed Results (Time in microseconds)

| Vector Size | Naive Insertion | Optimized Insertion |
|------------|-----------------|---------------------|
| 100 elements | 3.39 µs | N/A |
| 1,000 elements | 34.0 µs | N/A |
| 10,000 elements | 786 µs | N/A |
| 100,000 elements | 100,324 µs | N/A |

**Note:** Optimized version benchmarks are pending implementation.

## Tests

The project includes unit tests covering:
- Empty vector
- Insertions with duplicates
- Insertions without new values
- Large insertions

## Contributing

Contributions are welcome! Please submit a pull request. 