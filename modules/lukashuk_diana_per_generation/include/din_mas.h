// Copyright 2022 Lukashuk Diana

#ifndef MODULES_LUKASHUK_D_LAB2_INCLUDE_DIN_MAS_H_
#define MODULES_LUKASHUK_D_LAB2_INCLUDE_DIN_MAS_H_
#include <iostream>
#include <ostream>

class din_mas {
 private:
  int m_size;
  int* m_data;

 public:
  din_mas();
  din_mas(const din_mas& a);
  explicit din_mas(int size);

  int min_elem();
  void resize(int size);
  void del_elem(int nom);
  void del_elem_zn(int chislo);
  void push_back(int val);
  int size() const;
  int& operator[](int i);
  bool have_this_el(int a);
  din_mas operator=(din_mas mc);
  bool operator==(const din_mas& a);

  ~din_mas();
};
//  std::ostream& operator << (std::ostream& out,  din_mas& a);

#endif  // MODULES_LUKASHUK_D_LAB2_INCLUDE_DIN_MAS_H_
