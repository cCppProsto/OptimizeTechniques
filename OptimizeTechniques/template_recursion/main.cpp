#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

size_t sum{0};

template <int N> class Factorial
{
  public:
    enum : unsigned long
    {
      GetValue = N * Factorial<N - 1>::GetValue
    };
};

template <> class Factorial<1>
{
  public:
    enum
    {
      GetValue = 1
    };
};


unsigned long recursive_fact(unsigned long n)
{
  if ((n==0)||(n==1))
    return 1;
  else
    return n*recursive_fact(n-1);
}


unsigned long non_recursive_fact(unsigned long n)
{
  unsigned long result = 1;
  for(unsigned long i = 2; i<=n; ++i)
  {
    result *= i;
  }
  return result;
}

//------------------------------------------------------------------------------
static void recursion(benchmark::State& state)
{
  for (auto _ : state)
  {
    sum += recursive_fact(100);
  }
}
BENCHMARK(recursion);

//------------------------------------------------------------------------------
static void non_recursion(benchmark::State& state)
{
  for (auto _ : state)
  {
    sum += non_recursive_fact(100);
  }
}
BENCHMARK(non_recursion);

//------------------------------------------------------------------------------
static void fact_template_recursion(benchmark::State& state)
{
  for (auto _ : state)
  {
    Factorial<100> f;
    sum += f.GetValue;
  }

  // Factorial<6> ->

  // 6 * Factorial<5>
  // 6 * 5 * Factorial<4>
  // 6 * 5 * 4 * Factorial<3>
  // 6 * 5 * 4 * 3 * Factorial<3>
  // 6 * 5 * 4 * 3 * 2 * Factorial<1>
  // 6 * 5 * 4 * 3 * 2 * 1
}
BENCHMARK(fact_template_recursion);

unsigned long summa(int *inOut, int n)
{
  unsigned long res = 0;
  for(int i = 0; i < n; ++i )
    sum += inOut[i];
  return res;
}

//------------------------------------------------------------------------------
static void summa_not_recursion(benchmark::State& state)
{
  int a[100];
  for (auto _ : state)
  {
    sum += summa(a, 100);
  }
}
BENCHMARK(summa_not_recursion);

template<int n>
inline unsigned long add(int *A)
{
  return A[n] + add<n-1>(A);
}

template<>
inline unsigned long add<0>(int *A)
{
  return A[0];
}

//------------------------------------------------------------------------------
static void summa_template_not_recursion(benchmark::State& state)
{
  int a[100];
  for (auto _ : state)
  {
    sum += add<99>(a);
  }
}
BENCHMARK(summa_template_not_recursion);

BENCHMARK_MAIN();
