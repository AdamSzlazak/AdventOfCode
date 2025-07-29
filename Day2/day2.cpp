#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool checkIfChangeDirect(std::vector<int> numbersToCheck) {
  bool isAscending = false, isAscendingSet = false;
  for (size_t i = 0; i < numbersToCheck.size() - 1; i++) {
    if (numbersToCheck[i] < numbersToCheck[i + 1]) {
      if (isAscending == false && isAscendingSet == true) {
        return true;
      }
      isAscending = true;
      isAscendingSet = true;
    } else if (numbersToCheck[i] > numbersToCheck[i + 1]) {
      if (isAscending == true && isAscendingSet) {
        return true;
      }
      isAscending = false;
      isAscendingSet = true;
    }
  }
  return false;
}
bool checkIfChangedDirectionDampener(std::vector<int> numbersToCheck) {
  bool isAscending = false, isAscendingSet = false;
  for (size_t i = 0; i < numbersToCheck.size() - 1; i++) {
    if (numbersToCheck[i] < numbersToCheck[i + 1]) {
      if (isAscending == false && isAscendingSet == true) {
        std::vector<int> numbersDampened = numbersToCheck;
        numbersDampened.erase(numbersDampened.begin() + i);
        bool dampenedResult = checkIfChangeDirect(numbersDampened);
        if (dampenedResult) {
          return true;
        }
      }
      isAscending = true;
      isAscendingSet = true;
    } else if (numbersToCheck[i] > numbersToCheck[i + 1]) {
      if (isAscending == true && isAscendingSet == true) {
        std::vector<int> numbersDampened = numbersToCheck;
        numbersDampened.erase(numbersDampened.begin() + i);
        bool dampenedResult = checkIfChangeDirect(numbersDampened);
        if (dampenedResult) {
          return true;
        }
      }
      isAscending = false;
      isAscendingSet = true;
    }
  }
  return false;
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

bool isSafer(std::vector<int> numbers) {
  bool dampened = false;
  for (int i = 0; i < numbers.size()-1; i++) {
    int lvlDiff = abs(numbers[i] - numbers[i + 1]);
    if (lvlDiff < 1 || lvlDiff > 3) {
      if (dampened) {
        return false;
      }
	  if(i+2> numbers.size()){
		  return false;
	  }
      int lvlDiff = abs(numbers[i] - numbers[i + 2]);
      if (lvlDiff >= 1 || lvlDiff <= 3) {
        dampened = true;
		i++;
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

int secondTask(std::string fileName) {
  bool isSafe;
  std::ifstream file(fileName);
  int tmpNumber, safeLevelCount = 0;
  std::vector<int> numbers;
  if (!file) {
    std::cerr << "Failed to open file\n";
  }

  for (std::string line; getline(file, line);) {
    std::istringstream tmpString(line);
    while (tmpString >> tmpNumber) {
      numbers.push_back(tmpNumber);
    }

    bool changingDirection = checkIfChangedDirectionDampener(numbers);
    if (changingDirection == false) {
      isSafe = isSafer(numbers);
      if (isSafe) {
        safeLevelCount++;
      }
    }
    numbers.clear();
  }
  return safeLevelCount;
}

int main(int argc, char **argv) {

  std::string fileName =
      "/Users/adamszlazak/Projects/AdventOfCode/Day2/input.txt";
  std::cout << firstTask(fileName) << std::endl;
  std::cout << secondTask(fileName) << std::endl;

  return 0;
}
