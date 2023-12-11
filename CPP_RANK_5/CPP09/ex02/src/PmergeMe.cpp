#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : type("none")
{
	
}

PmergeMe::PmergeMe(const PmergeMe& copy) : type(copy.type)
{
	*this = copy;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this == &other)
		return (*this);
	this->start = other.start;
	this->end = other.end;
	this->elapsedTime = other.elapsedTime;
	return (*this);
}

bool PmergeMe::extractPositiveIntegers(char **argv, std::vector<int> &integersVector, std::deque<int> &integersDeque)
{
	int					number;
	std::stringstream	numberStream;
	std::string 		inputString;

	inputString = std::string(argv[0]);	
	for (int i = 1; argv[i]; i++)
		inputString += " " + std::string(argv[i]);	
	numberStream << inputString;
	while (!numberStream.eof())
	{
		if (!(numberStream >> number))
			return (false);
		if (number < 0)
			return (false);
		if (std::find(integersVector.begin(), integersVector.end(), number) != integersVector.end())
			return (false);
		integersVector.push_back(number);
		integersDeque.push_back(number);
	}
	return (true);
}

void PmergeMe::mergeVectors(std::vector<std::vector<int> > &left, std::vector<std::vector<int> > &right, \
	std::vector<std::vector<int> > &result)
{
	result.clear();
	while (!left.empty() && !right.empty())
	{
		if (left[0][A] < right[0][A] || right[0][A] == UNUSED)
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}	
	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}
}

void PmergeMe::recursiveMergeSort(std::vector<std::vector<int> > &pairs)
{
	std::vector<std::vector<int> > left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::vector<std::vector<int> > right(pairs.begin() + pairs.size() / 2, pairs.end());

	if (pairs.size() == 1)
		return ;
	recursiveMergeSort(left);
	recursiveMergeSort(right);
	mergeVectors(left, right, pairs);
}

void PmergeMe::generateNumberPairs(const std::vector<int> &nums, std::vector<std::vector<int> > &pairs)
{
	size_t							numPairs = std::ceil(nums.size() / 2.0);

	pairs.resize(numPairs);
	pairs.assign(numPairs, std::vector<int>(2));
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if ((2 * i + 1) == nums.size())
		{
			pairs[i][A] = UNUSED;		
			pairs[i][B] = nums[2 * i];			
		}
		else
		{
			pairs[i][A] = MIN(nums[2 * i], nums[2 * i + 1]);
			pairs[i][B] = MAX(nums[2 * i], nums[2 * i + 1]);			
		}
	}
}

void PmergeMe::generateJacobsthalSequence(std::vector<size_t> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		vec[i] = (pow(2, i + 2) - pow(-1, i + 2)) / 3;
}

void PmergeMe::binarySearch(std::vector<int> &S, int number)
{
	int start, middle, end;

	start = 0;
	end = S.size() - 1;
	while (start <= end)
	{
		middle = start + (end - start) / 2;
		if (number > S[middle])
			start = middle + 1;
		else if (number < S[middle])		
			end = middle - 1;
	}
	S.insert(S.begin() + start, number);
}

void PmergeMe::insertionSort(std::vector<int> &S, size_t n, const std::vector<std::vector<int> > &pairs)
{
	std::vector<size_t>	jacobSequence(pairs.size());

	generateJacobsthalSequence(jacobSequence);
	binarySearch(S, pairs[0][B]);
	if (pairs.size() > 1)
		binarySearch(S, pairs[1][B]);
	for (size_t i = 1; i < jacobSequence.size(); i++)
	{
		for (size_t k = jacobSequence[i]; k > jacobSequence[i - 1]; k--)
		{
			if (k >= pairs.size())
				continue ;
			binarySearch(S, pairs[k][B]);
			if (S.size() == n)
				return ;
		}
	}
}

double PmergeMe::mergeInsertionSort(std::vector<int> &nums)
{
	std::vector<std::vector<int> >	pairs;
	std::vector<int>				S;
	
	start = std::chrono::high_resolution_clock::now();
	generateNumberPairs(nums, pairs);
	recursiveMergeSort(pairs);	
	for (size_t i = 0 ; i < pairs.size() && pairs[i][A] != UNUSED; i++)
		S.push_back(pairs[i][A]);
	insertionSort(S, nums.size(), pairs);
	end = std::chrono::high_resolution_clock::now();
	elapsedTime = end - start;
	nums = S;
	return (elapsedTime.count());
}


void PmergeMe::merge(std::deque<std::deque<int> > &left, std::deque<std::deque<int> > &right, \
	std::deque<std::deque<int> > &result)
{
	result.clear();
	while (!left.empty() && !right.empty())
	{
		if (left[0][A] < right[0][A] || right[0][A] == UNUSED)
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}	
	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}
}

void PmergeMe::mergeSort(std::deque<std::deque<int> > &pairs)
{
	std::deque<std::deque<int> > left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::deque<std::deque<int> > right(pairs.begin() + pairs.size() / 2, pairs.end());

	if (pairs.size() == 1)
		return ;
	mergeSort(left);
	mergeSort(right);
	merge(left, right, pairs);
}

void PmergeMe::createPairs(const std::deque<int> &nums, std::deque<std::deque<int> > &pairs)
{
	size_t							numPairs = std::ceil(nums.size() / 2.0);

	pairs.resize(numPairs);
	pairs.assign(numPairs, std::deque<int>(2));
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if ((2 * i + 1) == nums.size())
		{
			pairs[i][A] = UNUSED;		
			pairs[i][B] = nums[2 * i];			
		}
		else
		{
			pairs[i][A] = MIN(nums[2 * i], nums[2 * i + 1]);
			pairs[i][B] = MAX(nums[2 * i], nums[2 * i + 1]);			
		}
	}
}

void PmergeMe::generateJacobsthalSequence(std::deque<size_t> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		vec[i] = (pow(2, i + 2) - pow(-1, i + 2)) / 3;
}

void PmergeMe::binarySearch(std::deque<int> &S, int number)
{
	int start, middle, end;

	start = 0;
	end = S.size() - 1;
	while (start <= end)
	{
		middle = start + (end - start) / 2;
		if (number > S[middle])
			start = middle + 1;
		else if (number < S[middle])		
			end = middle - 1;
	}
	S.insert(S.begin() + start, number);
}

void PmergeMe::insertionSort(std::deque<int> &S, size_t n, const std::deque<std::deque<int> > &pairs)
{
	std::deque<size_t>	jacobSequence(pairs.size());

	generateJacobsthalSequence(jacobSequence);
	binarySearch(S, pairs[0][B]);
	if (pairs.size() > 1)
		binarySearch(S, pairs[1][B]);
	for (size_t i = 1; i < jacobSequence.size(); i++)
	{
		for (size_t k = jacobSequence[i]; k > jacobSequence[i - 1]; k--)
		{
			if (k >= pairs.size())
				continue ;
			binarySearch(S, pairs[k][B]);
			if (S.size() == n)
				return ;
		}
	}
}

double PmergeMe::mergeInsertionSort(std::deque<int> &nums)
{
	std::deque<std::deque<int> >	pairs;
	std::deque<int>				S;
	
	start = std::chrono::high_resolution_clock::now();
	createPairs(nums, pairs);
	mergeSort(pairs);	
	for (size_t i = 0 ; i < pairs.size() && pairs[i][A] != UNUSED; i++)
		S.push_back(pairs[i][A]);
	insertionSort(S, nums.size(), pairs);
	end = std::chrono::high_resolution_clock::now();
	elapsedTime = end - start;
	nums = S;
	return (elapsedTime.count());
}