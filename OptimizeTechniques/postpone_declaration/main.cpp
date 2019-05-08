#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

static bool flag{true};

//------------------------------------------------------------------------------
static void not_postpone_int(benchmark::State& state)
{
  for (auto _ : state)
  {
    int i{0};
    if(flag)
    {
      i = std::rand()%10000;
      flag = !flag;
    }
  }
}
BENCHMARK(not_postpone_int);

//------------------------------------------------------------------------------
static void postpone_int(benchmark::State& state)
{
  for (auto _ : state)
  {
    if(flag)
    {
      int i{std::rand()%10000};
      flag = !flag;
    }
  }
}
BENCHMARK(postpone_int);

//------------------------------------------------------------------------------
static void not_postpone_string(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string i{""};
    if(flag)
    {
      i = "std::rand()%10000";
      flag = !flag;
    }
  }
}
BENCHMARK(not_postpone_string);

//------------------------------------------------------------------------------
static void postpone_string(benchmark::State& state)
{
  for (auto _ : state)
  {
    if(flag)
    {
      std::string i{"std::rand()%10000"};
      flag = !flag;
    }
  }
}
BENCHMARK(postpone_string);


BENCHMARK_MAIN();
