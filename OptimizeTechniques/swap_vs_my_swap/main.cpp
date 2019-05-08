#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <benchmark/benchmark.h>


template <class T>
void my_swap(T& a, T& b)
{
  T t = a;
  a = b;
  b = t;
}


//------------------------------------------------------------------------------
static void std_swap_vector(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::vector<int> v_1;
    std::vector<int> v_2;
    v_1.resize(1000);
    v_2.resize(10000);
    std::swap(v_1, v_2);
  }
}
BENCHMARK(std_swap_vector);

//------------------------------------------------------------------------------
static void std_swap_list(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::list<int> v_1;
    std::list<int> v_2;
    v_1.resize(1000);
    v_2.resize(10000);
    std::swap(v_1, v_2);
  }
}
BENCHMARK(std_swap_list);

//------------------------------------------------------------------------------
static void std_swap_int(benchmark::State& state)
{
  for (auto _ : state)
  {
    int v_1{1};
    int v_2{2};
    std::swap(v_1, v_2);
  }
}
BENCHMARK(std_swap_int);

//------------------------------------------------------------------------------
static void std_swap_string(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string v_1{"Hello"};
    std::string v_2{"world!!"};
    std::swap(v_1, v_2);
  }
}
BENCHMARK(std_swap_string);


//------------------------------------------------------------------------------
static void my_swap_vector(benchmark::State& state)
{
  std::cout << std::endl;
  for (auto _ : state)
  {
    std::vector<int> v_1;
    std::vector<int> v_2;
    v_1.resize(1000);
    v_2.resize(10000);
    my_swap(v_1, v_2);
  }
}
BENCHMARK(my_swap_vector);

//------------------------------------------------------------------------------
static void my_swap_list(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::list<int> v_1;
    std::list<int> v_2;
    v_1.resize(1000);
    v_2.resize(10000);
    my_swap(v_1, v_2);
  }
}
BENCHMARK(my_swap_list);

//------------------------------------------------------------------------------
static void my_swap_int(benchmark::State& state)
{
  for (auto _ : state)
  {
    int v_1{1};
    int v_2{2};
    my_swap(v_1, v_2);
  }
}
// Register the function as a benchmark
BENCHMARK(my_swap_int);

//------------------------------------------------------------------------------
static void my_swap_string(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string v_1{"Hello"};
    std::string v_2{"world!!"};
    my_swap(v_1, v_2);
  }
}
BENCHMARK(my_swap_string);

BENCHMARK_MAIN();
