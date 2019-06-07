#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

const int size = 10000;
int a[size];
int b[size];
bool gBool{false};

size_t sum{0};

void f_a (int i, bool x)
{
  for (i = 0; i < size; i++)
    if (x)
      sum += a[i];
    else
      sum += b[i];
}

void f_b (int i, bool x)
{
  if (x)
    for (i = 0; i < size; i++)
      sum += a[i];
  else
    for (i = 0; i < size; i++)
      sum += b[i];
}

//------------------------------------------------------------------------------
static void switching(benchmark::State& state)
{
  for (auto _ : state)
  {
    f_a(1000, gBool);
    gBool = !gBool;
  }
}
BENCHMARK(switching);
BENCHMARK(switching);
BENCHMARK(switching);

//------------------------------------------------------------------------------
static void unswitching(benchmark::State& state)
{
  for (auto _ : state)
  {
    f_b(1000, gBool);
    gBool = !gBool;
  }
}
BENCHMARK(unswitching);
BENCHMARK(unswitching);
BENCHMARK(unswitching);

BENCHMARK_MAIN();
