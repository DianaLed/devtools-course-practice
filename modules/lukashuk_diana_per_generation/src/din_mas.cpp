// Copyright 2022 Lukashuk Diana

#include "include/din_mas.h"

#include <stdbool.h>

#include <limits>
#include <string>

din_mas::din_mas() {
  m_size = 0;
  m_data = NULL;
}

din_mas::din_mas(const din_mas& a) {
  m_size = a.m_size;
  if (m_data == NULL) m_data;
  if (m_size != 0)
    m_data = new int[m_size];
  else
    m_data = 0;
  for (int i = 0; i < m_size; ++i) m_data[i] = a.m_data[i];
}

din_mas::din_mas(int size) {
  m_size = size;
  if (size != 0)
    m_data = new int[size];
  else
    m_data = NULL;
}

int din_mas::min_elem() {
  if (m_size > 0) {
    int res = m_data[0];
    for (int i = 1; i < m_size; i++) {
      if (res > m_data[i]) res = m_data[i];
    }
    return res;
  }
  return 0;
}

void din_mas::resize(int size) {
  if (size != m_size) {
    int new_capacity = std::max(size, m_size * 2);
    int* new_data = new int[new_capacity];
    for (int i = 0; i < m_size; ++i) new_data[i] = m_data[i];
    if (m_data != NULL) delete[] m_data;
    m_data = new_data;
  }
  m_size = size;
}

void din_mas::del_elem(int nom) {
  if (nom >= 0 && nom < m_size) {
    din_mas d_new(m_size - 1);
    int j = 0;
    for (int i = 0; i < m_size; i++) {
      if (i != nom) {
        d_new[j] = m_data[i];
        j++;
      }
    }
    if (m_data) delete[] m_data;
    m_size = d_new.m_size;
    m_data = new int[m_size];
    for (int i = 0; i < m_size; i++) m_data[i] = d_new.m_data[i];
  }
}

void din_mas::del_elem_zn(int chislo) {
  for (int i = 0; i < m_size; i++) {
    if (m_data[i] == chislo) {
      this->del_elem(i);
      break;
    }
  }
}

void din_mas::push_back(int val) {
  resize(m_size + 1);
  m_data[m_size - 1] = val;
}

int din_mas::size() const { return m_size; }

int& din_mas::operator[](int i) { return m_data[i]; }

bool din_mas::have_this_el(int a) {
  for (int i = 0; i < m_size; i++) {
    if (a == m_data[i]) return 1;
  }
  return 0;
}

din_mas din_mas::operator=(din_mas mc) {
  if (m_data) delete[] m_data;
  m_size = mc.m_size;
  m_data = new int[m_size];
  for (int i = 0; i < m_size; i++) m_data[i] = mc.m_data[i];
  return *this;
}

bool din_mas::operator==(const din_mas& a) {
  if (a.m_size != m_size) return false;
  for (int i = 0; i < a.m_size; i++) {
    if (a.m_data[i] != m_data[i]) return false;
  }
  return true;
}

din_mas::~din_mas() {
  if (m_data) delete[] m_data;
}

// std::ostream& operator<<(std::ostream& out, din_mas& a) {
//  for (int i = 0; i < a.size(); i++) {
//    out << a[i] << " ";
//  }
//  out << "\n";
//  return out;
// }
