#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

template <class T> void ByValue(T t) { }
template <class T> void ByReference(const T& t) { }
template <class T> void ByPointer(const T* t) { }

//------------------------------------------------------------------------------
static void pass_int_by_value(benchmark::State& state)
{
  for (auto _ : state)
  {
    int i{0};
    ByValue(i);
  }
}
BENCHMARK(pass_int_by_value);

//------------------------------------------------------------------------------
static void pass_int_by_reference(benchmark::State& state)
{
  for (auto _ : state)
  {
    int i{0};
    ByReference(i);
  }
}
BENCHMARK(pass_int_by_reference);


//------------------------------------------------------------------------------
static void pass_int_by_pointer(benchmark::State& state)
{
  for (auto _ : state)
  {
    int i{0};
    ByPointer(&i);
  }
}
BENCHMARK(pass_int_by_pointer);

//------------------------------------------------------------------------------
static void pass_string_by_value(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string str{"Hello"};
    ByValue(str);
  }
}
BENCHMARK(pass_string_by_value);

//------------------------------------------------------------------------------
static void pass_string_by_reference(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string str{"Hello"};
    ByReference(str);
  }
}
BENCHMARK(pass_string_by_reference);


//------------------------------------------------------------------------------
static void pass_string_by_pointer(benchmark::State& state)
{
  for (auto _ : state)
  {
    std::string str{"Hello"};
    ByPointer(&str);
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
    ByValue(data);
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
    ByReference(data);
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
    ByPointer(&data);
  }
}
BENCHMARK(pass_vector_by_pointer);

BENCHMARK_MAIN();
