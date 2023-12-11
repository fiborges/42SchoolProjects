#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>
# include <chrono>
# include <cmath>
# include <vector>
# include <deque>
# include <algorithm>

# define UNUSED -1
# define A 0
# define B 1
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) > (b) ? (a) : (b))

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class PmergeMe
{
	private:
		const std::string type;
		std::chrono::high_resolution_clock::time_point start, end;
		std::chrono::duration<double> elapsedTime;
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& right);
		
		double mergeInsertionSort(std::vector<int> &nums);
		double mergeInsertionSort(std::deque<int> &nums);
		bool extractPositiveIntegers(char **argv, std::vector<int> &vec, std::deque<int> &deque);

	private:
		
		void generateNumberPairs(const std::vector<int> &nums, std::vector<std::vector<int> > &pairs);
		void recursiveMergeSort(std::vector<std::vector<int> > &pairs);
		void mergeVectors(std::vector<std::vector<int> > &left, std::vector<std::vector<int> > &right, \
			std::vector<std::vector<int> > &result);
		void generateJacobsthalSequence(std::vector<size_t> &vec);
		void insertionSort(std::vector<int> &S, size_t n, const std::vector<std::vector<int> > &pairs);
		void binarySearch(std::vector<int> &S, int number);

		void generateJacobsthalSequence(std::deque<size_t> &vec);
		void mergeSort(std::deque<std::deque<int> > &pairs);
		void merge(std::deque<std::deque<int> > &left, std::deque<std::deque<int> > &right, \
			std::deque<std::deque<int> > &result);
		void createPairs(const std::deque<int> &nums, std::deque<std::deque<int> > &pairs);
		void insertionSort(std::deque<int> &S, size_t n, const std::deque<std::deque<int> > &pairs);
		void binarySearch(std::deque<int> &S, int number);
};

#endif