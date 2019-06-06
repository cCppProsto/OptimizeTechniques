#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

static volatile int gSomeValue{0};
static double gVal_1{0};
static double gVal_2{0};

//------------------------------------------------------------------------------
static void loop_float_index(benchmark::State& state)
{
  for (auto _ : state)
  {
    for(float i = 0.; i < 100000.; ++i)
    {
      switch(gSomeValue)
      {
        case 1:
        {
          gVal_1 = i * 10.;
          break;
        }
        case 2:
        {
          gVal_2 = i * 20.;
          break;
        }
        default:
        {
          gSomeValue = 0;
          break;
        }
      }
      gSomeValue++;
    }
  }
}
BENCHMARK(loop_float_index);

//------------------------------------------------------------------------------
static void loop_double_index(benchmark::State& state)
{
  for (auto _ : state)
  {
    for(double i = 0.; i < 100000.; ++i)
    {
      switch(gSomeValue)
      {
        case 1:
        {
          gVal_1 = i * 10.;
          break;
        }
        case 2:
        {
          gVal_2 = i * 20.;
          break;
        }
        default:
        {
          gSomeValue = 0;
          break;
        }
      }
      gSomeValue++;
    }
  }
}
BENCHMARK(loop_double_index);

//------------------------------------------------------------------------------
static void loop_int_index(benchmark::State& state)
{
  for (auto _ : state)
  {
    for(int i = 0; i < 100000; ++i)
    {
      switch(gSomeValue)
      {
        case 1:
        {
          gVal_1 = i * 10.;
          break;
        }
        case 2:
        {
          gVal_1 = i * 10.;
          break;
        }
        default:
        {
          gSomeValue = 0;
          break;
        }
      }
      gSomeValue++;
    }
  }
}
BENCHMARK(loop_int_index);



BENCHMARK_MAIN();
