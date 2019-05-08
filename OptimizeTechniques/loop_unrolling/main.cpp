#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>


void g()
{

}

//------------------------------------------------------------------------------
static void loop_not_unrolling(benchmark::State& state)
{
  for (auto _ : state)
  {
    for (int i = 0; i < 100000; i++)
      g ();
  }
}
BENCHMARK(loop_not_unrolling);

//------------------------------------------------------------------------------
static void loop_unrolling(benchmark::State& state)
{
  for (auto _ : state)
  {
    for (int i = 0; i < 100000; i += 2)
    {
      g ();
      g ();
    }
  }
}
BENCHMARK(loop_unrolling);

BENCHMARK_MAIN();
