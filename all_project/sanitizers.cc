#include <iostream>

using namespace std;

int ASan(int argc) {
  int *array = new int[100];
  delete[] array;
  return array[argc];  // BOOM
}

int USan(int argc) {
  int k = 0x7fffffff;
  k += argc;
  return 0;
}

int main(int argc, char **argv) {
  cout << "argc: " << argc << endl;
  if (argc % 2 == 0) {
    cout << "if branch\n";
    ASan(argc);
  } else {
    cout << "else branch\n";
    USan(argc);
  }
}

// c++ -fsanitize=undefined -fsanitize=address sanitizers.cc