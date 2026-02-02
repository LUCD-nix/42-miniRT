#!/bin/env sh
# Run error cases in error_test directory with valgrind
for file in error_tests/*.rt error_tests/*.txt; do
    echo "Testing: $file"
    ./miniRT "$file"
    echo "---"
done