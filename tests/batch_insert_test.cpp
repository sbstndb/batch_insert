#include <gtest/gtest.h>
#include "batch_insert.h"
#include <vector>

TEST(BatchInsertTest, NaiveEmptyVector) {
    std::vector<int> vec;
    std::vector<int> values = {1, 3, 2};
    
    batch_insert::naive_batch_insert(vec, values);
    EXPECT_EQ(vec, std::vector<int>({1, 2, 3}));
}

TEST(BatchInsertTest, OptimizedEmptyVector) {
    std::vector<int> vec;
    std::vector<int> values = {1, 3, 2};
    
    batch_insert::optimized_batch_insert(vec, values);
    EXPECT_EQ(vec, std::vector<int>({1, 2, 3}));
}

TEST(BatchInsertTest, NaiveWithDuplicates) {
    std::vector<int> vec = {1, 3, 5};
    std::vector<int> values = {2, 3, 4, 5};
    
    batch_insert::naive_batch_insert(vec, values);
    EXPECT_EQ(vec, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(BatchInsertTest, OptimizedWithDuplicates) {
    std::vector<int> vec = {1, 3, 5};
    std::vector<int> values = {2, 3, 4, 5};
    
    batch_insert::optimized_batch_insert(vec, values);
    EXPECT_EQ(vec, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(BatchInsertTest, NaiveNoNewValues) {
    std::vector<int> vec = {1, 2, 3};
    std::vector<int> values = {1, 2, 3};
    
    batch_insert::naive_batch_insert(vec, values);
    EXPECT_EQ(vec, std::vector<int>({1, 2, 3}));
}

TEST(BatchInsertTest, OptimizedNoNewValues) {
    std::vector<int> vec = {1, 2, 3};
    std::vector<int> values = {1, 2, 3};
    
    batch_insert::optimized_batch_insert(vec, values);
    EXPECT_EQ(vec, std::vector<int>({1, 2, 3}));
}

TEST(BatchInsertTest, NaiveLargeInsert) {
    std::vector<int> vec = {1, 5, 10};
    std::vector<int> values = {2, 3, 4, 6, 7, 8, 9};
    
    batch_insert::naive_batch_insert(vec, values);
    EXPECT_EQ(vec, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
}

TEST(BatchInsertTest, OptimizedLargeInsert) {
    std::vector<int> vec = {1, 5, 10};
    std::vector<int> values = {2, 3, 4, 6, 7, 8, 9};
    
    batch_insert::optimized_batch_insert(vec, values);
    EXPECT_EQ(vec, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
} 