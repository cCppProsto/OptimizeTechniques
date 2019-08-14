#include <iostream>
#include <benchmark/benchmark.h>

struct sServers
{
  bool power_is_ok{false};
  bool network_is_ok{false};
  bool storage_is_ok{false};
};

constexpr int array_size{10000};
sServers g_servers[array_size];

bool g_flag{false};
size_t g_count{0};
size_t g_count2{0};
//------------------------------------------------------------------------------
static void data_init(benchmark::State &state)
{
  for (auto _ : state)
  {
    for(int i = 0; i < array_size; ++i)
    {
      g_servers[i].power_is_ok = g_flag;
      g_flag = !g_flag;

      g_servers[i].network_is_ok = g_flag;
      g_flag = !g_flag;

      g_servers[i].storage_is_ok = g_flag;
      g_flag = !g_flag;
    }
  }
}
BENCHMARK(data_init);

//------------------------------------------------------------------------------
static void boolean_and_not_optimize(benchmark::State& state)
{
  for (auto _ : state)
  {
    for(int i = 0; i < array_size; ++i)
    {
      if(   g_servers[i].power_is_ok
         && g_servers[i].network_is_ok
         && g_servers[i].storage_is_ok)
      {
        g_count++;
      }
    }
  }
}
BENCHMARK(boolean_and_not_optimize);
BENCHMARK(boolean_and_not_optimize);
BENCHMARK(boolean_and_not_optimize);

//------------------------------------------------------------------------------
static void boolean_and_optimize(benchmark::State& state)
{
  for (auto _ : state)
  {
    for(int i = 0; i < array_size; ++i)
    {
      if(  g_servers[i].power_is_ok
         & g_servers[i].network_is_ok
         & g_servers[i].storage_is_ok)
      {
        g_count2++;
      }
    }
  }
}
BENCHMARK(boolean_and_optimize);
BENCHMARK(boolean_and_optimize);
BENCHMARK(boolean_and_optimize);

//------------------------------------------------------------------------------
BENCHMARK_MAIN();
