#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

int res{0};

int foo_a(int &a, int &b)
{
  return a + b;
}

inline int foo_b(int &a, int &b)
{
  return a + b;
}

//------------------------------------------------------------------------------
static void no_inline(benchmark::State& state)
{
  for (auto _ : state)
  {
    for(int i = 0; i < 1000; ++i)
      res += foo_a(res, res);
  }
}
BENCHMARK(no_inline);
BENCHMARK(no_inline);
BENCHMARK(no_inline);

//------------------------------------------------------------------------------
static void yes_inline(benchmark::State& state)
{
  for (auto _ : state)
  {
    for(int i = 0; i < 1000; ++i)
      res += foo_b(res, res);
  }
}
BENCHMARK(yes_inline);
BENCHMARK(yes_inline);
BENCHMARK(yes_inline);

BENCHMARK_MAIN();
