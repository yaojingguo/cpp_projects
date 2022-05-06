#include <iostream>
#include <string>
#include <vector>

#include "absl/container/flat_hash_map.h"
#include "absl/strings/str_format.h"
#include "absl/strings/str_join.h"
#include "absl/strings/string_view.h"

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

int main() {
  Join();
  Format();
  Container();
  StringView();
  return 0;
}
