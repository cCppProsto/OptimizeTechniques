#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

int g_int{0};

typedef struct { int x, y, z; } Point3;
typedef struct { Point3 *pos, *direction; } Object;

void not_oprimized(Object *p)
{
  p->pos->x = 0;
  p->pos->y = 0;
  p->pos->z = 0;
}

void oprimized(Object *p)
{
  Point3 *pos = p->pos;
  pos->x = 0;
  pos->y = 0;
  pos->z = 0;
}


//------------------------------------------------------------------------------
static void f_not_optimized(benchmark::State& state)
{
  Object p;
  p.pos = new Point3;
  p.direction = new Point3;
  for (auto _ : state)
  {
    for(int i = 0; i < 10000; ++i)
      not_oprimized(&p);
  }
}
BENCHMARK(f_not_optimized);

//------------------------------------------------------------------------------
static void f_optimized(benchmark::State& state)
{
  Object p;
  p.pos = new Point3;
  p.direction = new Point3;
  for (auto _ : state)
  {
    for(int i = 0; i < 10000; ++i)
      oprimized(&p);
  }
}
BENCHMARK(f_optimized);

BENCHMARK_MAIN();
