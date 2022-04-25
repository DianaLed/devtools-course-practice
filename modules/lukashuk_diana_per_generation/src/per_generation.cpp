// Copyright 2022 Lukashuk Diana

#include "include/per_generation.h"

#include <stdbool.h>

#include <limits>
#include <string>

void PerGeneration::inp_size_pair() {
  int res = 1;
  int resinwhile = 1;
  dinmas copy;
  copy = inp;
  while (copy.size() != 0) {
    for (int i = 1; i < copy.size(); i++) {
      if (copy[0] == copy[i]) {
        resinwhile++;
        copy.del_elem(i);
      }
    }
    copy.del_elem(0);
    res = res * factorial(resinwhile);
    resinwhile = 1;
  }
  if (inp.size() == 0)
    size_pair = 0;
  else
    size_pair = factorial(inp.size()) / res;
}

PerGeneration::PerGeneration() {
  res = NULL;
  size_pair = 0;
}

PerGeneration::PerGeneration(dinmas input) {
  inp = input;
  inp_size_pair();
  res = new dinmas[size_pair];
}

PerGeneration::PerGeneration(const PerGeneration& a) {
  inp = a.inp;
  if (size_pair > 0) delete[] res;
  size_pair = a.size_pair;
  res = new dinmas[size_pair];
  for (int i = 0; i < a.inp.size(); i++) {
    res[i] = a.res[i];
  }
}

int PerGeneration::get_size_pair() { return size_pair; }

bool PerGeneration::have_in_res(dinmas n) {
  for (int a = 0; a < size_pair; a++) {
    if (res[a] == n) return 1;
  }
  return 0;
}

void PerGeneration::PG_work() {
  int size_inp_t = inp.size();
  int point_t = 0;
  int rs = 0;
  dinmas* new_res = new dinmas[factorial(inp.size())];
  dinmas copy_time;
  int min_c;
  while (size_inp_t != 0) {
    rs = factorial(size_inp_t - 1);
    copy_time = inp;
    while (copy_time.size() != 0) {
      {
        int a = 0;
        a = inp.size() - size_inp_t;
        if (a != 0) {
          for (int i = 0; i < a; i++)
            copy_time.del_elem_zn(new_res[point_t][i]);
        }
      }
      min_c = copy_time.min_elem();
      for (int i = point_t; i < point_t + rs; i++) new_res[i].push_back(min_c);
      point_t = point_t + rs;
      copy_time.del_elem_zn(min_c);
    }
    if (point_t == factorial(inp.size())) {
      size_inp_t--;
      point_t = 0;
    }
  }
  rs = 0;
  point_t = add(*this);
  for (int i = 0; i < size_pair && rs < factorial(inp.size()); i++) {
    if (!have_in_res(new_res[rs])) res[i] = new_res[rs];
    rs++;
  }
  if (new_res) delete[] new_res;
}

PerGeneration::~PerGeneration() {
  if (res) delete[] res;
}

int factorial(int num) {
  int res = 1;
  for (int i = num; i > 1; i--) res = res * i;
  return res;
}

int add(PerGeneration b) {
  int a = 0;
  if (b.get_size_pair() != 0) a++;
  return a;
}
