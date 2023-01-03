#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
using std::string;

class RuntimeException {
  private:
    string errorMsg;
  public:
    RuntimeException(const string &err) {errorMsg = err;}
    string getMessage() const {return errorMsg;}
};

class IndexOutOfBounds : public RuntimeException {
  public:
    IndexOutOfBounds(const string& err): RuntimeException(err) {};
};

#endif