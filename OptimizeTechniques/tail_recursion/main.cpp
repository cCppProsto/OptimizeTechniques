#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

int res{0};

int g(int i)
{
  switch (i)
  {
    case 0: return 1;
    case 10: return 121;
    case 210: return 12323;
    case 12210: return 134;
  }
  return 90;
}

int f_a (int i)
{
  if (i > 0)
  {
    res += g (i);
    return f_a (i - 1);
  }
  else
    return 0;
}

int f_b (int i)
{
 entry:
  if (i > 0)
  {
    res += g (i);
    i--;
    goto entry;
  }
  else
    return 0;
}

//------------------------------------------------------------------------------
static void recursion(benchmark::State& state)
{
  for (auto _ : state)
  {
    f_a(10000);
  }
}
BENCHMARK(recursion);
BENCHMARK(recursion);
BENCHMARK(recursion);

//------------------------------------------------------------------------------
static void tail_recursion(benchmark::State& state)
{
  for (auto _ : state)
  {
    f_b(10000);
  }
}
BENCHMARK(tail_recursion);
BENCHMARK(tail_recursion);
BENCHMARK(tail_recursion);

BENCHMARK_MAIN();
