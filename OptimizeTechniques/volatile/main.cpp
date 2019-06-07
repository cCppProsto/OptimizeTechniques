#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

const int size = 10000;
int a[size];
int b[size];
volatile int x, y;

void f_a ()
{
  for (int i = 0; i < size; i++)
    a[i] = x + y;
}

void f_b ()
{
  int temp = x + y;
  for (int i = 0; i < size; i++)
    a[i] = temp;
}

//------------------------------------------------------------------------------
static void not_optimize(benchmark::State& state)
{
  for (auto _ : state)
  {
    f_a();
  }
}
BENCHMARK(not_optimize);
BENCHMARK(not_optimize);
BENCHMARK(not_optimize);

//------------------------------------------------------------------------------
static void optimize(benchmark::State& state)
{
  bool b;
  for (auto _ : state)
  {
    f_b();
  }
}
BENCHMARK(optimize);
BENCHMARK(optimize);
BENCHMARK(optimize);

BENCHMARK_MAIN();
