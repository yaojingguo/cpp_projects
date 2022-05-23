#include <iostream>
#include <string>
#include <vector>

#include "absl/container/flat_hash_map.h"
#include "absl/strings/str_format.h"
#include "absl/strings/str_join.h"
#include "absl/strings/string_view.h"
#include "absl/strings/escaping.h"
#include "absl/container/inlined_vector.h"
#include "absl/types/span.h"

void Join() {
  std::vector<std::string> v = {"foo", "bar", "baz", "z"};
  std::string s = absl::StrJoin(v, "-");
  std::cout << "Joined string: " << s << "\n";
}

void Format() {
  std::string s =
      absl::StrFormat("Welcome to %s, Number %d!", "The Village", 6);
  std::cout << s << std::endl;
}

void Container() {
  absl::flat_hash_map<int, std::string> map = {{10, "one"}, {20, "two"}};
  std::cout << map.contains(10) << std::endl;
  std::cout << map.contains(100) << std::endl;
}

void func(absl::string_view name) {
  std::cout << "My name is " << name << std::endl;
}

void StringView() {
  std::string name = "xiao yu";
  func(name);
}

void InlinedVector() {
  constexpr int N = 5;
  absl::InlinedVector<int, N> vec;
  
  for (int i = 1; i <= N; i++) {
    vec.push_back(i * 10);
  }

  for (int i = 1; i <= N; i++) {
    std::cout << vec[i-1] << std::endl;
  }
}

class Person {
public:
    Person(int no, int age) : no_(no), age_(age) {}
    Person(const Person& other) {
        no_ = other.no_;
        age_ = other.age_;
    }
    void info() {
        std::cout << "no: " << no_ << "age: " << age_ << std::endl;
    }

private:
    int no_;
    int age_;
};

void Vector() {
  std::vector<Person> vec;
  Person p1(1, 10);
  Person p2(1, 20);
  vec.push_back(p1);
  vec.push_back(p2);
}

void TakeSpan(absl::Span<const int> span) {
  for (auto v: span) {
    std::cout << v << std::endl;
  }
  std::cout << std::endl; 
} 

void Span() {
  int a[] = {10, 20, 30};
  TakeSpan(a);
}

void Base64() {
  std::string data = "ab\x11";
  std::string s = absl::BytesToHexString(data);
  std::cout << "hex: " << s << std::endl;

  std::string base64 = absl::Base64Escape(data);
  std::cout << "base64: " << base64 << std::endl;
}

int main() {
  // Join();
  // Format();
  // Container();
  // StringView();
  // InlinedVector();
  // Span();
  Base64();
  return 0;
}
