#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

const int size = 100000;
int a[size];
int b[size];

void f_a (int i, bool x)
{
  for (i = 0; i < size; i++)
    if (x)
      a[i] = 0;
    else
      b[i] = 0;
}

void f_b (int i, bool x)
{
  if (x)
    for (i = 0; i < size; i++)
      a[i] = 0;
  else
    for (i = 0; i < size; i++)
      b[i] = 0;
}

//------------------------------------------------------------------------------
static void switching(benchmark::State& state)
{
  bool b;
  for (auto _ : state)
  {
    f_a(1000, b);
  }
}
BENCHMARK(switching);

//------------------------------------------------------------------------------
static void unswitching(benchmark::State& state)
{
  bool b;
  for (auto _ : state)
  {
    f_b(1000, b);
  }
}
BENCHMARK(unswitching);

BENCHMARK_MAIN();
