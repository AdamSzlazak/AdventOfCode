#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
int firstTask(std::string fileName) {

  std::ifstream file(fileName);
  int tmpNumber, levelChange, safeLevels = 0;
  std::vector<int> numbers;
  bool isSafe = true, isAscending = true, isAscendingSet = false;

  if (!file)
    return -1;

  for (std::string line; std::getline(file, line);) {
    std::istringstream tmpString(line);
    while (tmpString >> tmpNumber) {
      numbers.push_back(tmpNumber);
    }
    for (size_t i = 0; i < numbers.size() - 1; i++) {
      if (numbers[i] < numbers[i + 1]) {
        if (isAscending == false && isAscendingSet == true) {
          isSafe = false;
        }
        isAscending = true;
        isAscendingSet = true;
      } else if (numbers[i] > numbers[i + 1]) {
        if (isAscending == true && isAscendingSet == true) {
          isSafe = false;
        }
        isAscending = false;
        isAscendingSet = true;
      } else if (numbers[i] > numbers[i + 1]) {
      }
      levelChange = abs(numbers[i] - numbers[i + 1]);
      if (levelChange < 1 || levelChange > 3) {
        isSafe = false;
      }
    }
    if (isSafe == true) {
      safeLevels++;
    }
    numbers.clear();
    isSafe = true;
    isAscendingSet = false;
  }
  return safeLevels;
}

int main(int argc, char **argv) {

  if (argc != 1) {
    int firstTaskResult = firstTask(argv[1]);
    std::cout << firstTaskResult << "\n";
  }

  return 0;
}
