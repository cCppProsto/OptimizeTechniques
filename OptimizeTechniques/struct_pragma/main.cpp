#include <iostream>
#include <benchmark/benchmark.h>

enum class eType : uint8_t
{
  Type_1,
  Type_2,
  Type_3,
  Type_4,
  Type_5,
  Type_6,
  Type_7
};

struct sNotOptimized
{
  eType type;
  double money;
  short id;
  // ...
  char symbol;
  unsigned long hash;
};

struct sOptimized
{
  char symbol;
  eType type;
  short id;
  unsigned long hash;
  double money;
};

#pragma pack(push, 1)
  struct sNotOptimizedPragma
  {
    eType type;
    double money;
    short id;
    // ...
    char symbol;
    unsigned long hash;
  };
#pragma pack(pop)

#pragma pack(push, 1)
  struct sOptimizedPragma
  {
    char symbol;
    eType type;
    short id;
    unsigned long hash;
    double money;
  };
#pragma pack(pop)

constexpr int array_size{10000};
static sNotOptimized array_no_optimized[array_size];
static sOptimized array_optimized[array_size];

static sNotOptimizedPragma array_no_optimized_pragma[array_size];
static sOptimizedPragma array_optimized_pragma[array_size];

//------------------------------------------------------------------------------
static void struct_not_optimised(benchmark::State& state)
{
#ifdef DEBUG_TEST
  std::cout << "struct_not_optimised:  "
            << sizeof(sNotOptimized)
            << ", common size array = "
            << sizeof(sNotOptimized) * array_size
            << std::endl;
#endif

  for (auto _ : state)
  {
    for(int i = 0; i < array_size; ++i)
    {
      array_no_optimized[i].id = i;
      array_no_optimized[i].hash = i ^ i*2;
      array_no_optimized[i].money = i * i;
      switch(i)
      {
        case 0:
        {
          array_no_optimized[i].type = eType::Type_1;
          array_no_optimized[i].symbol = 'A';
          break;
        }
        case 1:
        {
          array_no_optimized[i].type = eType::Type_2;
          array_no_optimized[i].symbol = 'B';
          break;
        }
        case 2:
        {
          array_no_optimized[i].type = eType::Type_3;
          array_no_optimized[i].symbol = 'C';
          break;
        }
        case 3:
        {
          array_no_optimized[i].type = eType::Type_4;
          array_no_optimized[i].symbol = 'D';
          break;
        }
        case 4:
        {
          array_no_optimized[i].type = eType::Type_5;
          array_no_optimized[i].symbol = 'E';
          break;
        }
        case 5:
        {
          array_no_optimized[i].type = eType::Type_6;
          array_no_optimized[i].symbol = 'F';
          break;
        }
        default:
        {
          array_no_optimized[i].type = eType::Type_7;
          array_no_optimized[i].symbol = 'G';
          break;
        }
      }
    }
  }
}
BENCHMARK(struct_not_optimised);

//------------------------------------------------------------------------------
static void struct_optimised(benchmark::State& state)
{
#ifdef DEBUG_TEST
  std::cout << "struct_not_optimised:  "
            << sizeof(sOptimized)
            << ", common size array = "
            << sizeof(sOptimized) * array_size
            << std::endl;
#endif

  for (auto _ : state)
  {
    for(int i = 0; i < array_size; ++i)
    {
      array_optimized[i].id = i;
      array_optimized[i].hash = i ^ i*2;
      array_optimized[i].money = i * i;
      switch(i)
      {
        case 0:
        {
          array_optimized[i].type = eType::Type_1;
          array_optimized[i].symbol = 'A';
          break;
        }
        case 1:
        {
          array_optimized[i].type = eType::Type_2;
          array_optimized[i].symbol = 'B';
          break;
        }
        case 2:
        {
          array_optimized[i].type = eType::Type_3;
          array_optimized[i].symbol = 'C';
          break;
        }
        case 3:
        {
          array_optimized[i].type = eType::Type_4;
          array_optimized[i].symbol = 'D';
          break;
        }
        case 4:
        {
          array_optimized[i].type = eType::Type_5;
          array_optimized[i].symbol = 'E';
          break;
        }
        case 5:
        {
          array_optimized[i].type = eType::Type_6;
          array_optimized[i].symbol = 'F';
          break;
        }
        default:
        {
          array_optimized[i].type = eType::Type_7;
          array_optimized[i].symbol = 'G';
          break;
        }
      }
    }
  }
}
BENCHMARK(struct_optimised);



//------------------------------------------------------------------------------
static void struct_not_optimised_pragma(benchmark::State& state)
{
#ifdef DEBUG_TEST
  std::cout << "struct_not_optimised_pragma:  "
            << sizeof(sNotOptimizedPragma)
            << ", common size array = "
            << sizeof(sNotOptimizedPragma) * array_size
            << std::endl;
#endif

  for (auto _ : state)
  {
    for(int i = 0; i < array_size; ++i)
    {
      array_no_optimized_pragma[i].id = i;
      array_no_optimized_pragma[i].hash = i ^ i*2;
      array_no_optimized_pragma[i].money = i * i;
      switch(i)
      {
        case 0:
        {
          array_no_optimized_pragma[i].type = eType::Type_1;
          array_no_optimized_pragma[i].symbol = 'A';
          break;
        }
        case 1:
        {
          array_no_optimized_pragma[i].type = eType::Type_2;
          array_no_optimized_pragma[i].symbol = 'B';
          break;
        }
        case 2:
        {
          array_no_optimized_pragma[i].type = eType::Type_3;
          array_no_optimized_pragma[i].symbol = 'C';
          break;
        }
        case 3:
        {
          array_no_optimized_pragma[i].type = eType::Type_4;
          array_no_optimized_pragma[i].symbol = 'D';
          break;
        }
        case 4:
        {
          array_no_optimized_pragma[i].type = eType::Type_5;
          array_no_optimized_pragma[i].symbol = 'E';
          break;
        }
        case 5:
        {
          array_no_optimized_pragma[i].type = eType::Type_6;
          array_no_optimized_pragma[i].symbol = 'F';
          break;
        }
        default:
        {
          array_no_optimized_pragma[i].type = eType::Type_7;
          array_no_optimized_pragma[i].symbol = 'G';
          break;
        }
      }
    }
  }
}
BENCHMARK(struct_not_optimised_pragma);

//------------------------------------------------------------------------------
static void struct_optimised_pragma(benchmark::State& state)
{
#ifdef DEBUG_TEST
  std::cout << "struct_not_optimised:  "
            << sizeof(sOptimizedPragma)
            << ", common size array = "
            << sizeof(sOptimizedPragma) * array_size
            << std::endl;
#endif

  for (auto _ : state)
  {
    for(int i = 0; i < array_size; ++i)
    {
      array_optimized_pragma[i].id = i;
      array_optimized_pragma[i].hash = i ^ i*2;
      array_optimized_pragma[i].money = i * i;
      switch(i)
      {
        case 0:
        {
          array_optimized_pragma[i].type = eType::Type_1;
          array_optimized_pragma[i].symbol = 'A';
          break;
        }
        case 1:
        {
          array_optimized_pragma[i].type = eType::Type_2;
          array_optimized_pragma[i].symbol = 'B';
          break;
        }
        case 2:
        {
          array_optimized_pragma[i].type = eType::Type_3;
          array_optimized_pragma[i].symbol = 'C';
          break;
        }
        case 3:
        {
          array_optimized_pragma[i].type = eType::Type_4;
          array_optimized_pragma[i].symbol = 'D';
          break;
        }
        case 4:
        {
          array_optimized_pragma[i].type = eType::Type_5;
          array_optimized_pragma[i].symbol = 'E';
          break;
        }
        case 5:
        {
          array_optimized_pragma[i].type = eType::Type_6;
          array_optimized_pragma[i].symbol = 'F';
          break;
        }
        default:
        {
          array_optimized_pragma[i].type = eType::Type_7;
          array_optimized_pragma[i].symbol = 'G';
          break;
        }
      }
    }
  }
}
BENCHMARK(struct_optimised_pragma);



//------------------------------------------------------------------------------
static void ffff(benchmark::State& state)
{
  for (auto _ : state)
  {
    for(int i = 0; i < array_size; ++i)
    {
      array_optimized_pragma[i].id = array_no_optimized_pragma[i].id;
      array_optimized[i].type = array_no_optimized[i].type;

      array_no_optimized_pragma[i].hash = array_optimized_pragma[i].hash;
      array_no_optimized[i].money = array_optimized[i].money;
    }
  }
}
BENCHMARK(ffff);

//------------------------------------------------------------------------------
BENCHMARK_MAIN();
