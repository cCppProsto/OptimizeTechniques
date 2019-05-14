#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

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
  int a{0};
  int b{0};
  for (auto _ : state)
  {
    foo_a(a, b);
  }
}
BENCHMARK(no_inline);

//------------------------------------------------------------------------------
static void yes_inline(benchmark::State& state)
{
  int a{0};
  int b{0};
  for (auto _ : state)
  {
    foo_b(a, b);
  }
}
BENCHMARK(yes_inline);

BENCHMARK_MAIN();
