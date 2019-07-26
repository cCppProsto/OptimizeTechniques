#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

constexpr int g_size = 30000;

struct Data1
{
  std::vector<int> items_a;
  std::vector<int> items_b;
};

struct Data2
{
  struct Item
  {
    int a;
    int b;
  };
  std::vector<Item> items;
};


//------------------------------------------------------------------------------
static void test_1(benchmark::State& state)
{
  Data1 data;
  data.items_a.resize(g_size);
  data.items_b.resize(g_size);

  for (auto _ : state)
  {
    for(int i = 0; i < g_size; ++i)
    {
      data.items_a[i] = i;
      data.items_b[i] = i;
    }
  }
}
BENCHMARK(test_1);
BENCHMARK(test_1);
BENCHMARK(test_1);


//------------------------------------------------------------------------------
static void test_2(benchmark::State& state)
{
  Data2 data;
  data.items.resize(g_size);

  for (auto _ : state)
  {
    for(int i = 0; i < g_size; ++i)
    {
      data.items[i].a = i;
      data.items[i].b = i;
    }
  }
}
BENCHMARK(test_2);
BENCHMARK(test_2);
BENCHMARK(test_2);


BENCHMARK_MAIN();
