#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

static bool gFlag{false};
//------------------------------------------------------------------------------
static void loop(benchmark::State& state)
{
  int a[100][300];
  for (auto _ : state)
  {
    for (int i = 0; i < 300; i++)
      for (int j = 0; j < 100; j++)
      {
        a[j][i] = gFlag ? 1 : 100;
        gFlag = !gFlag;
      }
  }
}
BENCHMARK(loop);

//------------------------------------------------------------------------------
static void loop_colapsing(benchmark::State& state)
{
  int a[100][300];
  for (auto _ : state)
  {
    int *p = &a[0][0];

    for (int i = 0; i < 30000; i++)
    {
      *p++ = gFlag ? 1 : 100;
      gFlag = !gFlag;
    }
  }
}
BENCHMARK(loop_colapsing);

BENCHMARK_MAIN();
