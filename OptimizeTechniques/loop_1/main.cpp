#include <benchmark/benchmark.h>

//------------------------------------------------------------------------------
static void loop_not_optimized(benchmark::State& state)
{
  for (auto _ : state)
  {
    int array[10000];
    int n = 10000;
    for(int i = 0; i < n; i++)
      array[i] = std::rand() % 1000;
  }
}
BENCHMARK(loop_not_optimized);
//------------------------------------------------------------------------------
static void loop_optimized(benchmark::State& state)
{
  for (auto _ : state)
  {
    int array[10000];
    int n = 10000;
    unsigned long end = reinterpret_cast<unsigned long>(array) + static_cast<unsigned long>(n);
    for(int *ptr = array; reinterpret_cast<unsigned long>(ptr) < end; ptr++)
      *ptr = std::rand() % 1000;
  }
}
BENCHMARK(loop_optimized);

//------------------------------------------------------------------------------
BENCHMARK_MAIN();
