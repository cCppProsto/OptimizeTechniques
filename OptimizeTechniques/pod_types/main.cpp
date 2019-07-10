#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <benchmark/benchmark.h>

static constexpr size_t arr_size{20000};

static bool is_equal{true};

struct sNotPOD
{
  sNotPOD()
    :a{1}
    ,b{2}
    ,c{3}
  {
  }

  sNotPOD &operator=(const sNotPOD &aObj)
  {
    a = aObj.a;
    b = aObj.b;
    c = aObj.c;
    return *this;
  }

  int a;
  int b;
  int c;
};


struct sPOD
{
  sPOD() = default;

  int a;
  int b;
  int c;
};

//------------------------------------------------------------------------------
static void copy_not_pod(benchmark::State& state)
{
  sNotPOD *array_1 = new sNotPOD[arr_size];
  sNotPOD *array_2 = new sNotPOD[arr_size]{};

  for (auto _ : state)
  {
    for(size_t i = 0; i < arr_size; ++i)
    {
      array_1[i] = array_2[i];
    }
  }

  delete [] array_1;
  delete [] array_2;
}
BENCHMARK(copy_not_pod);
BENCHMARK(copy_not_pod);
BENCHMARK(copy_not_pod);


//------------------------------------------------------------------------------
static void cmp_not_pod(benchmark::State& state)
{
  sNotPOD *array_1 = new sNotPOD[arr_size];
  sNotPOD *array_2 = new sNotPOD[arr_size]{};

  for (auto _ : state)
  {
    if(!is_equal)
      is_equal = true;
    for(size_t i = 0; i < arr_size; ++i)
    {
      if(array_1[i].a != array_2[i].a ||
         array_1[i].b != array_2[i].b ||
         array_1[i].c != array_2[i].c
         )
      {
        is_equal = false;
        break;
      }
    }
  }

  delete [] array_1;
  delete [] array_2;
}
BENCHMARK(cmp_not_pod);
BENCHMARK(cmp_not_pod);
BENCHMARK(cmp_not_pod);

//------------------------------------------------------------------------------
static void copy_pod(benchmark::State& state)
{
  sPOD *array_1 = new sPOD[arr_size];
  sPOD *array_2 = new sPOD[arr_size]{};

  for (auto _ : state)
  {
    std::memcpy(array_1, array_2, sizeof(sPOD) * arr_size);
  }
  delete [] array_1;
  delete [] array_2;
}
BENCHMARK(copy_pod);
BENCHMARK(copy_pod);
BENCHMARK(copy_pod);

//------------------------------------------------------------------------------
static void cmp_pod(benchmark::State& state)
{
  sPOD *array_1 = new sPOD[arr_size];
  sPOD *array_2 = new sPOD[arr_size]{};
  bool is_equal{true};

  for (auto _ : state)
  {
    if(!is_equal)
      is_equal = true;
    is_equal = std::memcmp(array_1, array_2, sizeof(sPOD) * arr_size);

    if(is_equal)
      array_2[100].a = 90;
    else
      array_2[100].a = 1;
  }

  delete [] array_1;
  delete [] array_2;

}

BENCHMARK(cmp_pod);
BENCHMARK(cmp_pod);
BENCHMARK(cmp_pod);

BENCHMARK_MAIN();
