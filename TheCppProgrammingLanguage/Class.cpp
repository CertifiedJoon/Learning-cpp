#include <bits/stdc++.h>

class complex {
  double re, im;
public:
  complex(double r, double i) : re{r}, im{i} {}
  complex(double r) : re{r}, im{0} {}
  complex() : re{0}, im{0} {}

  double real() const{return re;}
  void real(double d) {re = d;}
  double imag() const{return im;}
  void imag(double d) {im = d;}

  complex& operator+=(complex z){
    re += z.re;
    im += z.im;
    return *this;
  }
};

complex operator+(complex a, complex b) { return a+=b; }

class Vector{
public:
  Vector(std::initializer_list<double> lst)
    : elem {new double[lst.size()]}, sz {lst.size()}
  {
    copy(lst.begin(), lst.end(), elem);
  }
  Vector(int s) : elem{new double[s], sz {s}}

  ~Vector(){delete[] elem;}

  double& operator[](int i) {return elem[i];}
  int size() const {return sz;}
private:
  double* elem;
  int sz;
};

class Container{
public:
  virtual double& operator[](int) = 0;
  virtual int size() const = 0;
  virtual ~Container() {}
};

class vector_container : public Container{
public:
  vector_container(int s): v(s){}
  ~vector_container() {}

  double operator[](int i) override {return v[i];}
  int size() const override {return v.size();}
private:
  Vector v;
}

#include <iostream>

int main(){
  complex z = {1};
  z.real(2);
  std::cout << z.real() << std::endl;
}
