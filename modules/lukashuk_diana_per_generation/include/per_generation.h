// Copyright 2022 Lukashuk Diana

#ifndef MODULES_LUKASHUK_DIANA_PER_GENERATION_INCLUDE_PER_GENERATION_H_
#define MODULES_LUKASHUK_DIANA_PER_GENERATION_INCLUDE_PER_GENERATION_H_

#include "include/din_mas.h"

class PerGeneration {
 private:
  dinmas inp;
  dinmas* res;
  int size_pair;

  void inp_size_pair();

 public:
  PerGeneration();
  explicit PerGeneration(dinmas input);
  PerGeneration(const PerGeneration& a);

  int get_size_pair();
  bool have_in_res(dinmas n);
  void PG_work();

  ~PerGeneration();
};
// std::ostream& operator << (std::ostream& out, PerGeneration& a);
int factorial(int num);
int add(PerGeneration b);

#endif  // MODULES_LUKASHUK_DIANA_PER_GENERATION_INCLUDE_PER_GENERATION_H_
