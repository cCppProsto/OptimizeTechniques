#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

const int size = 100000;
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
static void switching(benchmark::State& state)
{
  bool b;
  for (auto _ : state)
  {
    f_a();
  }
}
BENCHMARK(switching);

//------------------------------------------------------------------------------
static void unswitching(benchmark::State& state)
{
  bool b;
  for (auto _ : state)
  {
    f_b();
  }
}
BENCHMARK(unswitching);

BENCHMARK_MAIN();
