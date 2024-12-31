#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool checkIfChangeDirect(std::vector<int> numbersToCheck)
{
	bool isAscending = false, isAscendingSet = false;
	for (size_t i = 0; i < numbersToCheck.size() - 1; i++)
	{
		if (numbersToCheck[i] < numbersToCheck[i + 1])
		{
			if (isAscending == false && isAscendingSet == true)
			{
				return true;
			}
			isAscending = true;
			isAscendingSet = true;
		}
		else if (numbersToCheck[i] > numbersToCheck[i + 1])
		{
			if (isAscending == true && isAscendingSet)
			{
				return true;
			}
			isAscending = false;
			isAscendingSet = true;
		}
	}
	return false;
}
bool checkIfChangedDirectionDampener(std::vector<int> numbersToCheck)
{
	bool isAscending = false, isAscendingSet = false;
	for (size_t i = 0; i < numbersToCheck.size() - 1; i++)
	{
		if (numbersToCheck[i] < numbersToCheck[i + 1])
		{
			if (isAscending == false && isAscendingSet == true)
			{
				std::vector<int> numbersDampened = numbersToCheck;
				numbersDampened.erase(numbersDampened.begin() + i);
				bool dampenedResult = checkIfChangeDirect(numbersDampened);
				if (dampenedResult)
				{
					return true;
				}
			}
			isAscending = true;
			isAscendingSet = true;
		}
		else if (numbersToCheck[i] > numbersToCheck[i + 1])
		{
			if (isAscending == true && isAscendingSet == true)
			{
				std::vector<int> numbersDampened = numbersToCheck;
				numbersDampened.erase(numbersDampened.begin() + i);
				bool dampenedResult = checkIfChangeDirect(numbersDampened);
				if (dampenedResult)
				{
					return true;
				}
			}
			isAscending = false;
			isAscendingSet = true;
		}
	}
	return false;
}
bool isLevelSafe(std::vector<int> numbersTocheck)
{
	int levelChange;
	for (size_t i = 0; i < numbersTocheck.size() - 1; i++)
	{
		levelChange = abs(numbersTocheck[i] - numbersTocheck[i + 1]);
		if (levelChange < 1 || levelChange > 3)
		{
			return false;
		}
	}
	return true;
}

bool isLevelSafeDampened(std::vector<int> numbersToCheck)
{
	int levelChange;
	for (size_t i = 0; i < numbersToCheck.size() - 1; i++)
	{
		levelChange = abs(numbersToCheck[i] - numbersToCheck[i + 1]);
		if (levelChange < 1 || levelChange > 3)
		{
			std::vector<int> numbersDampened = numbersToCheck;
			numbersDampened.erase(numbersDampened.begin() + i);
			bool isDampenedSafe = isLevelSafe(numbersDampened);
			if (!isDampenedSafe)
			{
				return false;
			}
		}
	}
	return true;
}
int firstTask(std::string fileName)
{
	int tmpNUmber, safeLevelsCount = 0;
	bool isSafe;
	std::vector<int> numbers;
	std::ifstream file(fileName);
	if (!file)
	{
		std::cerr << "Failed to open file\n";
		return -1;
	}

	for (std::string line; getline(file, line);)
	{
		std::istringstream tmpString(line);
		while (tmpString >> tmpNUmber)
		{
			numbers.push_back(tmpNUmber);
		}

		bool changingDirection = checkIfChangeDirect(numbers);
		if (changingDirection == false)
		{
			isSafe = isLevelSafe(numbers);
			if (isSafe)
			{
				safeLevelsCount++;
			}
		}
		numbers.clear();
	}
	return safeLevelsCount;
}

int secondTask(std::string fileName)
{
	bool isSafe;
	std::ifstream file(fileName);
	int tmpNumber, safeLevelCount = 0;
	std::vector<int> numbers;
	if (!file)
	{
		std::cerr << "Failed to open file\n";
	}

	for (std::string line; getline(file, line);)
	{
		std::istringstream tmpString(line);
		while (tmpString >> tmpNumber)
		{
			numbers.push_back(tmpNumber);
		}

		bool changingDirection = checkIfChangedDirectionDampener(numbers);
		if (changingDirection == false)
		{
			isSafe = isLevelSafeDampened(numbers);
			if (isSafe)
			{
				safeLevelCount++;
			}
		}
		numbers.clear();
	}
	return safeLevelCount;
}

int main(int argc, char **argv)
{

	if (argc != 1)
	{
		int firstTaskResult = firstTask(argv[1]);
		int secondTaskResult = secondTask(argv[1]);
		std::cout << firstTaskResult << "\n"
				  << secondTaskResult << "\n";
	}

	return 0;
}
