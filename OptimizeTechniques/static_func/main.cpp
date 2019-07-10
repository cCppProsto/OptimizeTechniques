#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

int res{0};
static int a_buffer[100000];

void foo_a(int aSize, int start)
{
  for(int i = start; i < aSize; ++i)
  {
    switch(i)
    {
      case 0:
      {
        a_buffer[i] = i;
        break;
      }
      case 3:
      {
        a_buffer[i] = i*3;
        break;
      }
      case 30:
      {
        a_buffer[i] = i*30;
        break;
      }
      case 9:
      {
        a_buffer[i] = i-1;
        break;
      }
      case 10:
      {
        a_buffer[i] = i-5;
        break;
      }
      default:
      {
        a_buffer[i] = i;
        break;
      }
    }
  }
}

static void foo_b(int aSize, int start)
{
  for(int i = start; i < aSize; ++i)
  {
    switch(i)
    {
      case 0:
      {
        a_buffer[i] = i;
        break;
      }
      case 3:
      {
        a_buffer[i] = i*3;
        break;
      }
      case 30:
      {
        a_buffer[i] = i*30;
        break;
      }
      case 9:
      {
        a_buffer[i] = i-1;
        break;
      }
      case 10:
      {
        a_buffer[i] = i-5;
        break;
      }
      default:
      {
        a_buffer[i] = i;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
static void no_inline(benchmark::State& state)
{
  for (auto _ : state)
  {
    foo_a(10000, 0);
  }
}
BENCHMARK(no_inline);
BENCHMARK(no_inline);
BENCHMARK(no_inline);

//------------------------------------------------------------------------------
static void yes_inline(benchmark::State& state)
{
  for (auto _ : state)
  {
    foo_b(10000, 0);
  }
}
BENCHMARK(yes_inline);
BENCHMARK(yes_inline);
BENCHMARK(yes_inline);

BENCHMARK_MAIN();
