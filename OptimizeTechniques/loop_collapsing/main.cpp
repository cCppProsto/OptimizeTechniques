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
      {
        if(a[j][i] == 1 || a[j][i] >= 100)
          a[j][i] = 0;
      }
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
    {
      if(*p == 1 || *p >= 100 )
        *p++ = 0;
    }
  }
}
BENCHMARK(loop_colapsing);

BENCHMARK_MAIN();
