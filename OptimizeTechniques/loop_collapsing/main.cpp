#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <benchmark/benchmark.h>

constexpr int w{100};
constexpr int h{300};

static size_t sum_1{0};
static size_t sum_2{0};

//------------------------------------------------------------------------------
static void loop(benchmark::State& state)
{
  int a[w][h];
  for (auto _ : state)
  {
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
      {
        sum_1 += a[j][i];
      }
  }
}
BENCHMARK(loop);
BENCHMARK(loop);
BENCHMARK(loop);

//------------------------------------------------------------------------------
static void loop_colapsing(benchmark::State& state)
{
  int a[w][h];
  for (auto _ : state)
  {
    int *p = &a[0][0];
    int end = w * h;
    for (int i = 0; i < end; i++)
    {
      sum_2 += *p++ ;
    }
  }
}
BENCHMARK(loop_colapsing);
BENCHMARK(loop_colapsing);
BENCHMARK(loop_colapsing);


BENCHMARK_MAIN();
