#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>


static size_t sum_1{0};
static size_t sum_2{0};

size_t g(int i)
{
  switch (i)
  {
    case 0: return 100;
    case 200: return 110;
    case 11: return 111;
    case 01: return 1001;
    case 112: return 10220;
  }
  return 0;
}

//------------------------------------------------------------------------------
static void loop_not_unrolling(benchmark::State& state)
{
  for (auto _ : state)
  {
    for (int i = 0; i < 10000; i++)
      sum_1 += g(i);
  }
}
BENCHMARK(loop_not_unrolling);
BENCHMARK(loop_not_unrolling);
BENCHMARK(loop_not_unrolling);

//------------------------------------------------------------------------------
static void loop_unrolling(benchmark::State& state)
{
  for (auto _ : state)
  {
    for (int i = 0; i < 10000; i += 10)
    {
      sum_1 += g(i);
      sum_2 += g(i+1);
      sum_1 += g(i+2);
      sum_2 += g(i+3);
      sum_1 += g(i+4);
      sum_1 += g(i+5);
      sum_1 += g(i+6);
      sum_1 += g(i+7);
      sum_1 += g(i+8);
      sum_1 += g(i+9);
    }
  }
}
BENCHMARK(loop_unrolling);
BENCHMARK(loop_unrolling);
BENCHMARK(loop_unrolling);

BENCHMARK_MAIN();
