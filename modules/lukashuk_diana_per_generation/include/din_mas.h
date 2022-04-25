// Copyright 2022 Lukashuk Diana

#ifndef MODULES_LUKASHUK_DIANA_PER_GENERATION_INCLUDE_DIN_MAS_H_
#define MODULES_LUKASHUK_DIANA_PER_GENERATION_INCLUDE_DIN_MAS_H_
#include <iostream>
#include <ostream>

class dinmas {
 private:
  int m_size;
  int* m_data;

 public:
  dinmas();
  dinmas(const dinmas& a);
  explicit dinmas(int size);

  int min_elem();
  void resize(int size);
  void del_elem(int nom);
  void del_elem_zn(int chislo);
  void push_back(int val);
  int size() const;
  int& operator[](int i);
  bool have_this_el(int a);
  dinmas operator=(dinmas mc);
  bool operator==(const dinmas& a);

  ~dinmas();
};
//  std::ostream& operator << (std::ostream& out,  din_mas& a);

#endif  // MODULES_LUKASHUK_DIANA_PER_GENERATION_INCLUDE_DIN_MAS_H_
