#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

static bool flag{true};

int res{0};

int get_int()
{
  switch (res)
  {
    case 0: return 1;
    case 10: return 121;
    case 210: return 12323;
    case 12210: return 134;
  }
  return 90;
}

//------------------------------------------------------------------------------
static void not_postpone_int(benchmark::State& state)
{
  for (auto _ : state)
  {
    int i{0};
    if(flag)
    {
      i = get_int();
      flag = !flag;
      res += i;
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
      int i{get_int()};
      flag = !flag;
      res += i;
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
      res += i.size();
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
      res += i.size();
    }
  }
}
BENCHMARK(postpone_string);


BENCHMARK_MAIN();
