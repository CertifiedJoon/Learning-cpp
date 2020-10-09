class CJvector{
public:
  CJvector(int s) : elem{new double[s]}, sz{s} {}
  double &operator[] (int i) {return elem[i];}
  int size() {return sz;}
private:
  double *elem;
  int sz;
};

struct entry{
  string name;
  variant <Node*, int> v;
}

void f(entry *pe){
  cout << <int>pe->v; // or <Node*>pe->v
}

int main(){
  CJvector v(6)
}
