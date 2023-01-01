#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

int print_size() {
  printf("\n======Varaible Size======\n");
  
  enum DAY {SUN, MON, TUE, WED, THU, FRI, SAT}; 
  printf("Size of bool: %d\n", sizeof(bool)); 
  printf("Size of char: %d\n", sizeof(char)); 
  printf("Size of int: %d\n", sizeof(int)); 
  printf("Size of short: %d\n", sizeof(short)); 
  printf("Size of long: %d\n", sizeof(long)); 
  printf("Size of float: %d\n", sizeof(float)); 
  printf("Size of double: %d\n", sizeof(double)); 
  printf("Size of Day: %d\n", sizeof(DAY)); 
  return EXIT_SUCCESS;
};

int dereferencing() {
  printf("\n=====Dereferencing=====\n");

  char ch = 'Q';
  char* p = &ch;
  cout << *p << endl;
  *p = 'Z';
  cout << ch << endl;

  return EXIT_SUCCESS;
};

int array_intro() {
  printf("\n====Array====\n");
  int m[10];
  int k[] = {1,2,3};
  int* p = k;
  cout << p[2] << endl;

  return EXIT_SUCCESS;
};

#include <string>
using std::string;
int string_intro(){
  printf("\n====String====\n");
  string s = "to be ";
  string t = "or ";
  string k = "not to be";
  s += t + k;
  cout << s << endl;
  return EXIT_SUCCESS;
};

int struct_intro() {
  enum Major {BENG, BBA, BSC};
  struct Student {
    string id;
    string name;
    int year;
    Major major;
  };
  Student stdnt = {"000000", "John Smith", 1, BENG};
  stdnt.name = "James Smith";
  cout << stdnt.name << endl;

  return EXIT_SUCCESS;
};

int dynamic_struct() {
  enum Major {BENG, BBA, BSC};
  struct Student {
    string id;
    string name;
    int year;
    Major major;
  };
  Student* p = new Student;
  p->name = "John Smith";
  cout << p->name << endl;
  delete p;
  return EXIT_SUCCESS;
};

int dynamic_array() {
  char* buffer = new char[500];
  buffer[0] = 'c';
  cout << buffer[0] << endl;
  delete buffer;
  return EXIT_SUCCESS;
}

int reference() {
  string author = "Samuel Clemens";
  string& penName = author;
  penName = "Mark Twain";
  cout << author << endl;
  
  return EXIT_SUCCESS;
};

int main() {
  // int x, y;
  // cout << "Please enter two numbers: ";
  // cin >> x >> y;
  // int sum = x + y;
  // cout << "Their sum is " << sum << endl;
  
  // print_size();
  // dereferencing();
  // array_intro();
  // string_intro();
  // struct_intro();
  // dynamic_struct();
  // dynamic_array();
  reference();

  return EXIT_SUCCESS;
};