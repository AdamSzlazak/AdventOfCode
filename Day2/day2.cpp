#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool checkIfChangeDirect(std::vector<int> numbers) {
  if (std::is_sorted(numbers.begin(), numbers.end())) {
    return false;
  }
  if (std::is_sorted(numbers.begin(), numbers.end(), std::greater<int>())) {
    return false;
  }
  return true;
}

bool isLevelSafe(std::vector<int> numbersTocheck) {
  int levelChange;
  for (size_t i = 0; i < numbersTocheck.size() - 1; i++) {
    levelChange = abs(numbersTocheck[i] - numbersTocheck[i + 1]);
    if (levelChange < 1 || levelChange > 3) {
      return false;
    }
  }
  return true;
}

bool isLevelSafeDampened(std::vector<int> numbersToCheck) {
  int levelChange;
  for (size_t i = 0; i < numbersToCheck.size() - 1; i++) {
    levelChange = abs(numbersToCheck[i] - numbersToCheck[i + 1]);
    if (levelChange < 1 || levelChange > 3) {
      std::vector<int> numbersDampened = numbersToCheck;
      numbersDampened.erase(numbersDampened.begin() + i);
      bool isDampenedSafe = isLevelSafe(numbersDampened);
      if (!isDampenedSafe) {
        return false;
      }
    }
  }
  return true;
}

int firstTask(std::string fileName) {
  int tmpNUmber, safeLevelsCount = 0;
  std::vector<int> numbers;
  std::ifstream file(fileName);
  if (!file.is_open()) {
    std::cerr << "Failed to open file\n";
    return -1;
  }

  for (std::string line; getline(file, line);) {
    std::istringstream tmpString(line);
    while (tmpString >> tmpNUmber) {
      numbers.push_back(tmpNUmber);
    }

    bool changingDirection = checkIfChangeDirect(numbers);
    if (changingDirection == false) {
      if (isLevelSafe(numbers)) {
        safeLevelsCount++;
      }
    }
    numbers.clear();
  }
  return safeLevelsCount;
}
bool checkIfChangedDirectionDampener(std::vector<int> numbersToCheck, bool dampened) {
	bool isAscending = false, isOrderSet = false;

	for(size_t i = 0; i< numbersToCheck.size(); i++)
	{
		if(numbers[i] < numbers[i+1])
		{
			if(!isAscending && isOrderSet)
		}
	}
}

int secondTask(std::string fileName) {
  int safeLevelCounter{0}, tmpNumber{0};
  std::vector<int> numbers;
  std::ifstream file(fileName);

  if (!file.is_open()) {
    std::cerr << "Failed to open file at path: " << fileName << "\n";
    return -1;
  }
  for (std::string line; getline(file, line);) {
    std::istringstream tmpString(line);
    while (tmpString >> tmpNumber) {
      numbers.push_back(tmpNumber);
    }

    return safeLevelCounter;
  }
}
int main(int argc, char **argv) {

#if defined(__linux__)
  std::string inputData = "/home/Grzywo/Projects/AdventOfCode/Day2/input.txt";
  std::string testData = "/home/Grzywo/Projects/AdventOfCode/Day2/testData.txt";
#elif defined(__APPLE__)
  std::string inputData =
      "/Users/adamszlazak/Projects/AdventOfCode/Day2/input.txt";
  std::string testData =
      "/Users/adamszlazak/Projects/AdventOfCode/Day2/testData.txt";
#endif

  std::cout << firstTask(inputData) << std::endl;
  std::cout << secondTask(testData) << std::endl;

  return 0;
}
