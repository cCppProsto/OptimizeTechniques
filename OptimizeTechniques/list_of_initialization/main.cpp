#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

class bad
{
public:
  bad(int aInt, std::string aStr)
  {
    m_int = aInt;
    m_str = aStr;
  }

private:
  int m_int;
  std::string m_str;
};

class good
{
public:
  good(int aInt, std::string aStr)
    :m_int{aInt}
    ,m_str{aStr}
  {
  }

private:
  int m_int;
  std::string m_str;
};

//------------------------------------------------------------------------------
static void init_list_not_used(benchmark::State& state)
{
  for (auto _ : state)
  {
    bad b(1, "Hello" );
  }
}
BENCHMARK(init_list_not_used);

//------------------------------------------------------------------------------
static void init_list_used(benchmark::State& state)
{
  for (auto _ : state)
  {
    good b(1, "Hello" );
  }
}
BENCHMARK(init_list_used);

BENCHMARK_MAIN();
