#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>


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
  data.items_a.resize(100000);
  data.items_b.resize(100000);

  for (auto _ : state)
  {
    for(int i = 0; i < 100000; ++i)
    {
      data.items_a[i] = i;
      data.items_b[i] = i;
    }
  }
}
BENCHMARK(test_1);


//------------------------------------------------------------------------------
static void test_2(benchmark::State& state)
{
  Data2 data;
  data.items.resize(100000);

  for (auto _ : state)
  {
    for(int i = 0; i < 100000; ++i)
    {
      data.items[i].a = i;
      data.items[i].b = i;
    }
  }
}
BENCHMARK(test_2);


BENCHMARK_MAIN();
