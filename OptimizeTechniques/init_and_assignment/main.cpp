#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

//------------------------------------------------------------------------------
static void init_and_assigment_int(benchmark::State& state)
{
  for (auto _ : state)
  {
    int i{0};
    int j{0};
    i = rand() % 10000;
    j = rand() % 10000;
  }
}
BENCHMARK(init_and_assigment_int);

//------------------------------------------------------------------------------
static void init_and_assigment_string(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string i;
    std::string j;
    i = "rand() % 10000";
    j = "rand() % 10000";
  }
}
BENCHMARK(init_and_assigment_string);


//------------------------------------------------------------------------------
static void init_int(benchmark::State& state)
{
  for (auto _ : state)
  {
    int i{rand() % 10000};
    int j{rand() % 10000};
  }
}
BENCHMARK(init_int);

//------------------------------------------------------------------------------
static void init_string(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string i{"rand() % 10000"};
    std::string j{"rand() % 10000"};
  }
}
BENCHMARK(init_string);

BENCHMARK_MAIN();
