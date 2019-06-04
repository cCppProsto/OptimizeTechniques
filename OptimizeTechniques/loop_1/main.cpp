#include <benchmark/benchmark.h>


constexpr int array_size{10000};

//------------------------------------------------------------------------------
static void loop_not_optimized(benchmark::State& state)
{
  for (auto _ : state)
  {
    int array[array_size];
    int n = array_size;
    for(int i = 0; i < n; i++)
    {
      array[i] = std::rand() % 1000;
    }
  }
}
BENCHMARK(loop_not_optimized);
//------------------------------------------------------------------------------
static void loop_optimized(benchmark::State& state)
{
  for (auto _ : state)
  {
    int array[array_size];
    int n = array_size;
    for(int *ptr = array; n; --n)
    {
      *(ptr++) = std::rand() % 1000;
    }
  }
}
BENCHMARK(loop_optimized);

//------------------------------------------------------------------------------
BENCHMARK_MAIN();
