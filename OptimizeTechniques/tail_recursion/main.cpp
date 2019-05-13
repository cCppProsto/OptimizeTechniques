#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

void g(int i)
{
}

int f_a (int i)
{
  if (i > 0)
    {
      g (i);
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
      g (i);
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
    f_a(1000);
  }
}
BENCHMARK(recursion);

//------------------------------------------------------------------------------
static void tail_recursion(benchmark::State& state)
{
  for (auto _ : state)
  {
    f_b(1000);
  }
}
BENCHMARK(tail_recursion);

BENCHMARK_MAIN();
