#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

int res{0};

class bad
{
public:
  bad(int aInt, std::string aStr)
  {
    m_int = aInt;
    m_str = aStr;
  }

  int i()
  {
    return m_int;
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
  int i()
  {
    return m_int;
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
    for (int i = 0; i < 10000; i++)
    {
      bad b(1, "Hello" );
      res += b.i();
    }
  }
}
BENCHMARK(init_list_not_used);
BENCHMARK(init_list_not_used);
BENCHMARK(init_list_not_used);

//------------------------------------------------------------------------------
static void init_list_used(benchmark::State& state)
{
  for (auto _ : state)
  {
    for (int i = 0; i < 10000; i++)
    {
      good g(1, "Hello" );
      res += g.i();
    }
  }
}
BENCHMARK(init_list_used);
BENCHMARK(init_list_used);
BENCHMARK(init_list_used);

BENCHMARK_MAIN();
