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
      array[i] = i*2;
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
    int i = 0;
    unsigned long end = reinterpret_cast<unsigned long>(array) + static_cast<unsigned long>(array_size)*sizeof(int);
    for(int *ptr = array; reinterpret_cast<unsigned long>(ptr) < end; ptr++)
    {
      *ptr = i * 2;
      ++i;
    }
  }
}
BENCHMARK(loop_optimized);


//------------------------------------------------------------------------------
static void loop_optimized_2(benchmark::State& state)
{
  for (auto _ : state)
  {
    int array[array_size];
    int n = array_size;
    int i = 0;
    for(int *ptr = array; n ; n--)
    {
      *(ptr++) = i * 2;
      ++i;
    }
  }
}
BENCHMARK(loop_optimized_2);
//------------------------------------------------------------------------------
BENCHMARK_MAIN();
