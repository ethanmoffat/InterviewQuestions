#pragma once

#include <string>
#include <list>
#include <memory>
#include <fstream>

class ProblemEngine
{
public:
	ProblemEngine() = delete;
	ProblemEngine(const ProblemEngine&) = delete;
	ProblemEngine& operator=(const ProblemEngine&) = delete;

	ProblemEngine(const std::string& inputFile)
	{
		_inputFile = std::ifstream(inputFile);
	}

	~ProblemEngine()
	{
		_inputFile.close();
	}

	bool IsFileOk() const { return !_inputFile.bad() && !_inputFile.eof(); }

	std::list<std::shared_ptr<int>> LoadTestCases()
	{
		if (!IsFileOk())
			throw std::exception("File could not be opened");

		int numberOfTestCases = 0;
		_inputFile >> numberOfTestCases;

		std::list<std::shared_ptr<int>> retList;

		for (int i = 0; i < numberOfTestCases; ++i)
		{
			int numberOfListItems = 0;
			_inputFile >> numberOfListItems;

			std::shared_ptr<int> listItemsForThisTestCase(new int[numberOfListItems]);
			for (int j = 0; j < numberOfListItems; ++j)
				_inputFile >> listItemsForThisTestCase.get()[j];

			retList.push_back(listItemsForThisTestCase);
		}

		return retList;
	}

private:
	std::ifstream _inputFile;
};