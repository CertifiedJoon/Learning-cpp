class CJvector{
public:
  CJvector(std::initializer_list<double> lst)
    : elem {new double[lst.size()]}, sz {lst.size()}
  {
    copy(lst.begin(), lst.end(), elem);
  }
  explicit CJvector(int s) : elem{new double[s], sz {s}}
  ~CJvector(){delete[] elem;}

  CJvector(const CJvector& a);
  CJvector& operator=(const CJvector& a);

  


  double& operator[](int i) {return elem[i];}
  int size() const {return sz;}
private:
  double* elem;
  int sz = 0;
};

CJvector::CJvector(const CJvector& a)
  :elem{new double[a.sz]},
   sz{a.sz}
{
  for (int i = 0; i < sz; ++i)
    elem[i] = a.elem[i];
};

CJvector& CJvector::operator=(const CJvector& a){
  double *p = new double[a.sz];
  for (int i = 0; i <a.sz; ++i)
    p[i] = a.elem[i];
  delete[] elem;
  elem = p;
  sz = a.sz;
  return *this
}
