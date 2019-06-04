#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>


int g(int i)
{
  if(i % 2)
    return 1;
  return 0;
}

//------------------------------------------------------------------------------
static void loop_not_unrolling(benchmark::State& state)
{
  for (auto _ : state)
  {
    for (int i = 0; i < 100000; i++)
      g (i);
  }
}
BENCHMARK(loop_not_unrolling);

//------------------------------------------------------------------------------
static void loop_unrolling(benchmark::State& state)
{
  for (auto _ : state)
  {
    for (int i = 0; i < 100000; i += 2)
    {
      g (i);
      g (i+1);
    }
  }
}
BENCHMARK(loop_unrolling);

BENCHMARK_MAIN();
