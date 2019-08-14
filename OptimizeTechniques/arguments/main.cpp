#include <benchmark/benchmark.h>
#include <string>

constexpr int N{10000};

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


int resss{0};

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
}data
{
  1.f,
   1.f,
   1.f,
   1.f,
   1.,
   1.,
   1.,
   1.,
   1,
   1,
   200,
   100,
   "cxzs",
   "aawws",
   "asdasd",
   "asdasdaasd"
};


int f_a(
const float &f1,
const float &f2,
const float &f3,
const float &f4,
const double &d1,
const double &d2,
const double &d3,
const double &d4,
const long &l1,
const long &l2,
const size_t &st1,
const size_t &st2,
const char *pstr1,
const char *pstr2,
const std::string &s1,
const std::string &s2
)
{
  int res = 0;
  res = f1 + f2;
  res = res * f3 / f4;
  res += d1 / res * d2;
  if(d3 > 12.0)
    res -= d3;
  if(res < 1000.0)
    res *= d4;

  if(l1 > l2)
  {
    if(s1.size() < 10)
    {
      res -= s1.size();
    }
    res += *pstr1;
  }
  else
  {
    if(st1 > st2)
      res -= s2.size();
    res -= *pstr2;
  }
  return res;
}

int f_b(const sData &data)
{
  int res = 0;
  res = data.f1 + data.f2;
  res = res * data.f3 / data.f4;
  res += data.d1 / res * data.d2;
  if(data.d3 > 12.0)
    res -= data.d3;
  if(res < 1000.0)
    res *= data.d4;

  if(data.l1 > data.l2)
  {
    if(data.s1.size() < 10)
    {
      res -= data.s1.size();
    }
    res += *data.pstr1;
  }
  else
  {
    if(data.st1 > data.st2)
      res -= data.s2.size();
    res -= *data.pstr2;
  }
  return res;
}

//------------------------------------------------------------------------------
static void many_arguments(benchmark::State& state)
{
  for (auto _ : state)
  {
    for(int i = 0; i < N; i++)
    {
      resss += f_a(
          f1,
          f2,
          f3,
          f4,
          d1,
          d2,
          d3,
          d4,
          l1,
          l2,
          st1,
          st2,
          pstr1,
          pstr2,
          s1,
          s2);
    }
  }

  f1 = f2 = f3;
  f4 = f1 / 2 - resss;
  d1 = f2 * 4;
  d2 = d3 / 4 * d4;
  l1 = l2 - 90 + resss;
  st1 = st2 + 12;
  s1 = pstr2;
  s2 = pstr1;

  data.f3 = f1 = f2;
  data.f4 = f3 + 2;
  data.d2 = f2 / 4 + resss;
  data.d1 = d3 * 4 * d4;
  data.l2 = l1 + 90 + resss;
  data.st2 = st1 - 12;
  data.s1 = pstr1;
  data.s2 = pstr2;
}
BENCHMARK(many_arguments);
BENCHMARK(many_arguments);
BENCHMARK(many_arguments);


//------------------------------------------------------------------------------
static void one_argument(benchmark::State& state)
{
  for (auto _ : state)
  {
    for(int i = 0; i < N; i++)
    {
      resss += f_b(data);
    }
  }

  f1 = f2 = f3;
  f4 = f1 + 2;
  d1 = f2 / 4;
  d2 = d3 * 4 * d4;
  l1 = l2 + 90;
  st2 = st1 - 12;
  s1 = pstr1;
  s2 = pstr2;

  data.f1 = f2 = f3;
  data.f4 = f1 + 2 - resss;
  data.d1 = f2 / 4;
  data.d2 = d3 * 4 * d4;
  data.l1 = l2 + 90 / resss;
  data.st2 = st1 - 12 + resss;
  data.s1 = pstr1;
  data.s2 = pstr2;
}
BENCHMARK(one_argument);
BENCHMARK(one_argument);
BENCHMARK(one_argument);

//------------------------------------------------------------------------------
BENCHMARK_MAIN();
