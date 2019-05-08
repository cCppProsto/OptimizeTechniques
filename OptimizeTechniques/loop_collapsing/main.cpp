#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

//------------------------------------------------------------------------------
static void loop(benchmark::State& state)
{
  int a[1000][300];
  for (auto _ : state)
  {
    for (int i = 0; i < 3000; i++)
      for (int j = 0; j < 1000; j++)
        a[j][i] = 0;
  }
}
BENCHMARK(loop);

//------------------------------------------------------------------------------
static void loop_colapsing(benchmark::State& state)
{
  int a[1000][300];
  for (auto _ : state)
  {
    int *p = &a[0][0];

    for (int i = 0; i < 300000; i++)
      *p++ = 0;
  }
}
BENCHMARK(loop_colapsing);

BENCHMARK_MAIN();
