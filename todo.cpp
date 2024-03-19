#include <iostream>
#include <map>
#include <ostream>
#include <string>

int end();
void create();

int main() {
  std::cout << "Todo App v.1\n";
  std::cout << "What would you like to create a list? Y/N\n";
  std::string answer;
  std::cin >> answer;
  if (answer == "Y") {
    create();
  } else {
    end();
  }

  return 0;
}

int end() {
  std::cout << "Note an answer. Try again\n";
  return 1;
}

void create() {
  std::map<std::string, std::string> todo;
  do {
    std::string key;
    std::string value;
    std::cout << "Enter number for priority of item\n";
    std::cin >> key;
    std::cout << "Enter todo item\n";
    std::cin >> value;
    todo[key] = value;
    std::cout << "Would you like to add more items Y/N\n";
    std::string answer;
    std::cin >> answer;
    if (answer == "Y") {
      create();
      break;
    }
    std::cout << "Would you like to remove items the list? Y/N\n";
    std::string removed;
    std::cin >> removed;
    if (removed == "Y") {
      std::cout << "What would you like to remove? Enter number of priority\n";
      std::string n;
      std::cin >> n;
      todo.erase(n);
    }
    break;
  } while (true);
  for (auto s : todo) {
    std::cout << s.first << " " << s.second << std::endl;
  }
}
