#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

//------------------------------------------------------------------------------
static void loop_not_fusion(benchmark::State& state)
{
  int a[3000];
  int b[1500];
  for (auto _ : state)
  {
    for (int i = 0; i < 3000; i++)
      a[i] = a[i] + 3;

    // ...

    for (int i = 0; i < 1500; i++)
      b[i] = b[i] + 4;
  }
}
BENCHMARK(loop_not_fusion);

//------------------------------------------------------------------------------
static void loop_fusion(benchmark::State& state)
{
  int a[3000];
  int b[1500];
  for (auto _ : state)
  {
    for (int i = 0; i < 3000; i++)
    {
      a[i] = a[i] + 3;
      if(i < 1500)
        b[i] = b[i] + 4;
    }
  }
}
BENCHMARK(loop_fusion);

BENCHMARK_MAIN();
