// Copyright 2022 Lukashuk Diana

#ifndef MODULES_LUKASHUK_D_LAB2_INCLUDE_PER_GENERATION_H_
#define MODULES_LUKASHUK_D_LAB2_INCLUDE_PER_GENERATION_H_

#include "include/din_mas.h"

class PerGeneration {
 private:
  din_mas inp;
  din_mas* res;
  int size_pair;

  void inp_size_pair();

 public:
  PerGeneration();
  explicit PerGeneration(din_mas input);
  PerGeneration(const PerGeneration& a);

  din_mas get_res(int index);

  int get_size_pair();
  bool have_in_res(din_mas n);
  void PG_work();

  ~PerGeneration();
};
// std::ostream& operator << (std::ostream& out, PerGeneration& a);
int factorial(int num);

#endif  // MODULES_LUKASHUK_D_LAB2_INCLUDE_PER_GENERATION_H_
