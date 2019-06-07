#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

template <class T> T ByValue(T t) { return t;}
template <class T> T ByReference(const T& t) { return t;}
template <class T> T ByPointer(const T* t) { return *t;}

int gi;
std::vector<int> vi;
std::string gs;

//------------------------------------------------------------------------------
static void pass_int_by_value(benchmark::State& state)
{
  for (auto _ : state)
  {
    int i{0};
    gi = ByValue(i);
  }
}
BENCHMARK(pass_int_by_value);

//------------------------------------------------------------------------------
static void pass_int_by_reference(benchmark::State& state)
{
  for (auto _ : state)
  {
    int i{0};
    gi = ByReference(i);
  }
}
BENCHMARK(pass_int_by_reference);


//------------------------------------------------------------------------------
static void pass_int_by_pointer(benchmark::State& state)
{
  for (auto _ : state)
  {
    int i{0};
    gi = ByPointer(&i);
  }
}
BENCHMARK(pass_int_by_pointer);

//------------------------------------------------------------------------------
static void pass_string_by_value(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string str{"Hello"};
    gs = ByValue(str);
  }
}
BENCHMARK(pass_string_by_value);

//------------------------------------------------------------------------------
static void pass_string_by_reference(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string str{"Hello"};
    gs = ByReference(str);
  }
}
BENCHMARK(pass_string_by_reference);


//------------------------------------------------------------------------------
static void pass_string_by_pointer(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string str{"Hello"};
    gs = ByPointer(&str);
  }
}
BENCHMARK(pass_string_by_pointer);


//------------------------------------------------------------------------------
static void pass_vector_by_value(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::vector<int> data;
    data.resize(10000);
    vi = ByValue(data);
  }
}
BENCHMARK(pass_vector_by_value);

//------------------------------------------------------------------------------
static void pass_vector_by_reference(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::vector<int> data;
    data.resize(10000);
    vi = ByReference(data);
  }
}
BENCHMARK(pass_vector_by_reference);


//------------------------------------------------------------------------------
static void pass_vector_by_pointer(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::vector<int> data;
    data.resize(10000);
    vi = ByPointer(&data);
  }
}
BENCHMARK(pass_vector_by_pointer);

BENCHMARK_MAIN();
