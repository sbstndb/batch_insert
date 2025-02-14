#include <benchmark/benchmark.h>
#include "batch_insert.h"
#include <random>
#include <algorithm>

// Fonction utilitaire pour générer des données de test
std::vector<int> generate_sorted_vector(size_t size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> offset(1, 10); // Décalage aléatoire entre les valeurs
    
    std::vector<int> vec;
    vec.reserve(size);
    
    int current = 0;
    for(size_t i = 0; i < size; ++i) {
        vec.push_back(current);
        current += 100 + offset(gen); // Espacement minimal de 100 entre les valeurs
    }
    
    return vec;
}

std::vector<int> generate_random_values(size_t size, int max_value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, max_value);
    
    std::vector<int> values(size);
    std::generate(values.begin(), values.end(), [&]() { return dis(gen); });
    return values;
}


std::vector<int> generate_negative_random_values(size_t size, int max_value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, max_value);

    std::vector<int> values(size);
    std::generate(values.begin(), values.end(), [&]() { return dis(gen); });
    return values;
}


static void BM_NaiveBatchInsert(benchmark::State& state) {
    const size_t vec_size = state.range(0);
    const size_t values_size = state.range(1);
    
    for (auto _ : state) {
        state.PauseTiming();
        auto vec = generate_sorted_vector(vec_size);
        auto values = generate_random_values(values_size, vec_size * 2);
        state.ResumeTiming();
        
        batch_insert::naive_batch_insert(vec, values);
    }
}

static void BM_OptimizedBatchInsert(benchmark::State& state) {
    const size_t vec_size = state.range(0);
    const size_t values_size = state.range(1);
    
    for (auto _ : state) {
        state.PauseTiming();
        auto vec = generate_sorted_vector(vec_size);
        auto values = generate_random_values(values_size, vec_size * 2);
        state.ResumeTiming();
        
        batch_insert::optimized_batch_insert(vec, values);
    }
}

static void BM_OptimizedBatchInsertByValue(benchmark::State& state) {
    const size_t vec_size = state.range(0);
    const size_t values_size = state.range(1);
    
    for (auto _ : state) {
        state.PauseTiming();
        auto vec = generate_sorted_vector(vec_size);
        auto values = generate_random_values(values_size, vec_size * 2);
        state.ResumeTiming();
        
        batch_insert::optimized_batch_insert2(vec, std::move(values));
    }
}

// Test avec différentes tailles de vecteurs et de valeurs à insérer
BENCHMARK(BM_NaiveBatchInsert)
    ->Args({100, 10})    // Petit vecteur, peu d'insertions
    ->Args({1000, 100})  // Moyen vecteur, insertions moyennes
    ->Args({10000, 1000}) // Grand vecteur, beaucoup d'insertions
    ->Args({100000, 10000})			  // 
    ->Args({100000, 1})    // Petit vecteur, peu d'insertions   
    ->Args({100000, 10})    // Petit vecteur, peu d'insertions
    ->Args({100000, 100})  // Moyen vecteur, insertions moyennes
    ->Args({100000, 1000}) // Grand vecteur, beaucoup d'insertions
    ->Args({100000, 10000})                       // 
    ->Args({100000, 100000})    // Petit vecteur, peu d'insertions						  // 
    ->Unit(benchmark::kMicrosecond);

BENCHMARK(BM_OptimizedBatchInsert)
    ->Args({100, 10})
    ->Args({1000, 100})
    ->Args({10000, 1000})
    ->Args({100000, 10000})
    ->Args({1000000, 100000})	
    ->Args({10000000, 1000000})	
    ->Args({100000, 1})    // Petit vecteur, peu d'insertions   
    ->Args({100000, 10})    // Petit vecteur, peu d'insertions
    ->Args({100000, 100})  // Moyen vecteur, insertions moyennes
    ->Args({100000, 1000}) // Grand vecteur, beaucoup d'insertions
    ->Args({100000, 10000})                       // 
    ->Args({100000, 100000})    // Petit vecteur, peu d'insertions	
    ->Unit(benchmark::kMicrosecond);

BENCHMARK(BM_OptimizedBatchInsertByValue)
    ->Args({100, 10})
    ->Args({1000, 100})
    ->Args({10000, 1000})
    ->Args({100000, 10000})	
    ->Args({1000000, 100000})
    ->Args({100000, 1})    // Petit vecteur, peu d'insertions   
    ->Args({100000, 10})    // Petit vecteur, peu d'insertions
    ->Args({100000, 100})  // Moyen vecteur, insertions moyennes
    ->Args({100000, 1000}) // Grand vecteur, beaucoup d'insertions
    ->Args({100000, 10000})                       // 
    ->Args({100000, 100000})    // Petit vecteur, peu d'insertions	
    ->Unit(benchmark::kMicrosecond);

















BENCHMARK_MAIN(); 
