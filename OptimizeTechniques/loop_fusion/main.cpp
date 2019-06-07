#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

static constexpr size_t arr_size_1{3000};
static constexpr size_t arr_size_2{1500};

static size_t sum_1{0};
static size_t sum_2{0};

//------------------------------------------------------------------------------
static void loop_not_fusion(benchmark::State& state)
{
  int a[arr_size_1];
  int b[arr_size_2];
  for (auto _ : state)
  {
    for (size_t i = 0; i < arr_size_1; i++)
      sum_1 += a[i];

    // ...

    for (size_t i = 0; i < arr_size_2; i++)
      sum_1 += b[i];
  }
}
BENCHMARK(loop_not_fusion);
BENCHMARK(loop_not_fusion);
BENCHMARK(loop_not_fusion);

//------------------------------------------------------------------------------
static void loop_fusion(benchmark::State& state)
{
  int a[arr_size_1];
  int b[arr_size_2];
  for (auto _ : state)
  {
    for (size_t i = 0; i < arr_size_1; i++)
    {
      sum_2 += a[i];
      if(i < arr_size_2)
        sum_2 += b[i];
    }
  }
}
BENCHMARK(loop_fusion);
BENCHMARK(loop_fusion);
BENCHMARK(loop_fusion);

BENCHMARK_MAIN();
