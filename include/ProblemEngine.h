#pragma once

#include <string>
#include <list>
#include <memory>
#include <fstream>

template<typename T = int>
struct TestCase
{
	std::list<std::shared_ptr<T>> Datas;
	std::list<int> Sizes;
};

template<typename T = int>
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

	bool IsFileOk() const { return !_inputFile.bad() && !_inputFile.eof() && _inputFile.is_open(); }

	std::list<TestCase<T>> LoadTestCases(int inputsPerCase = 1)
	{
		if (!IsFileOk())
			throw std::exception("File could not be opened");

		int numberOfTestCases = 0;
		_inputFile >> numberOfTestCases;

		std::list<TestCase<T>> retList;

		for (int i = 0; i < numberOfTestCases; ++i)
		{
			std::list<int> numbersOfInputs;
			for (int inp = 0; inp < inputsPerCase; ++inp)
			{
				int numberOfListItemsThisInput = 0;
				_inputFile >> numberOfListItemsThisInput;
				numbersOfInputs.push_back(numberOfListItemsThisInput);
			}

			TestCase<T> testCase;
			for (const auto elementsInSpecificInput : numbersOfInputs)
			{
				std::shared_ptr<T> listItemsForThisTestCase(new T[elementsInSpecificInput]);
				for (int j = 0; j < elementsInSpecificInput; ++j)
					_inputFile >> listItemsForThisTestCase.get()[j];

				testCase.Datas.push_back(listItemsForThisTestCase);
				testCase.Sizes.push_back(elementsInSpecificInput);
			}

			retList.push_back(testCase);
		}

		return retList;
	}

private:
	std::ifstream _inputFile;
};