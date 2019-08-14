#include <benchmark/benchmark.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

float f1{1.f};
float f2{1.f};
float f3{1.f};
float f4{1.f};
double d1{1.};
double d2{1.};
double d3{1.};
double d4{1.};
long l1{1};
long l2{1};
size_t st1{200};
size_t st2{100};
char *pstr1{"cxzs"};
char *pstr2{"aawws"};
std::string s1{"asdasd"};
std::string s2{"asdasdaasd"};

struct sData
{
  float f1;
  float f2;
  float f3;
  float f4;
  double d1;
  double d2;
  double d3;
  double d4;
  long l1;
  long l2;
  size_t st1;
  size_t st2;
  char * pstr1;
  char * pstr2;
  std::string s1;
  std::string s2;
};


constexpr int N{40000};
std::vector<sData> gv1;
std::vector<sData> gv2;

//------------------------------------------------------------------------------
static void init(benchmark::State& state)
{
  gv1.clear();
  for (auto _ : state)
  {
    gv1.reserve(N);
    for(int i = 0; i < N; i++)
    {
      sData tmp{};
      tmp.f3 = f1 = f2;
      tmp.f4 = f3 + 2;
      tmp.d2 = f2 / 4;
      tmp.d1 = d3 * 4 * d4;
      tmp.l2 = l1 + 90;
      tmp.st2 = st1 - 12;
      tmp.s1 = pstr1;
      tmp.s2 = pstr2;
      gv1[i] = tmp;
    }
  }

  f1 = f2 = f3;
  f4 = f1 / 2;
  d1 = f2 * 4;
  d2 = d3 / 4 * d4;
  l1 = l2 - 90;
  st1 = st2 + 12;
  s1 = pstr2;
  s2 = pstr1;
}
BENCHMARK(init);
BENCHMARK(init);
BENCHMARK(init);


//------------------------------------------------------------------------------
static void not_init(benchmark::State& state)
{
  gv2.clear();
  for (auto _ : state)
  {
    gv2.reserve(N);
    for(int i = 0; i < N; i++)
    {
      sData tmp;
      tmp.f3 = f1 = f2;
      tmp.f4 = f3 + 2;
      tmp.d2 = f2 / 4;
      tmp.d1 = d3 * 4 * d4;
      tmp.l2 = l1 + 90;
      tmp.st2 = st1 - 12;
      tmp.s1 = pstr1;
      tmp.s2 = pstr2;
      gv2[i] = tmp;
    }
  }

  f1 = f2 = f3;
  f4 = f2 / d1;
  d1 = f1 * 4;
  d3 = d2 / 4 * d1;
  l1 = l2 - 90;
  st1 = st1 + 12 - st2;
  s1 = pstr1;
  s2 = pstr2;
}
BENCHMARK(not_init);
BENCHMARK(not_init);
BENCHMARK(not_init);

//------------------------------------------------------------------------------
BENCHMARK_MAIN();











