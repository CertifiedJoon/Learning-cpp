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

class QueueEmpty : public RuntimeException {
  public:
    QueueEmpty(const string &err) : RuntimeException(err) {}
};

class QueueFull : public RuntimeException {
  public:
    QueueFull(const string &err) : RuntimeException(err) {}
};

class StackEmpty : public RuntimeException {
  public:
    StackEmpty(const string& err) : RuntimeException(err) {}
};

class StackFull : public RuntimeException {
  public:
    StackFull(const string& err) : RuntimeException(err) {}
};

class DequeEmpty : public RuntimeException {
  public:
    DequeEmpty(const string& err) : RuntimeException(err) {}
};

#endif