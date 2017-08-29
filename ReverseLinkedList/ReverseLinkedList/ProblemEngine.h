#pragma once

#include <string>
#include <list>
#include <memory>
#include <fstream>

struct TestCase
{
	std::shared_ptr<int> Data;
	int Size;

	TestCase(const std::shared_ptr<int> data, int size)
		: Data(data), Size(size) { }
};

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

	std::list<TestCase> LoadTestCases()
	{
		if (!IsFileOk())
			throw std::exception("File could not be opened");

		int numberOfTestCases = 0;
		_inputFile >> numberOfTestCases;

		std::list<TestCase> retList;

		for (int i = 0; i < numberOfTestCases; ++i)
		{
			int numberOfListItems = 0;
			_inputFile >> numberOfListItems;

			std::shared_ptr<int> listItemsForThisTestCase(new int[numberOfListItems]);
			for (int j = 0; j < numberOfListItems; ++j)
				_inputFile >> listItemsForThisTestCase.get()[j];

			retList.push_back(TestCase(listItemsForThisTestCase, numberOfListItems));
		}

		return retList;
	}

private:
	std::ifstream _inputFile;
};