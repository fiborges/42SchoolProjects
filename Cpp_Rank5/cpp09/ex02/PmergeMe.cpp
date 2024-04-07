/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:55:52 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/07 12:55:52 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::throwException(void)
{
	deqconteiner.clear();
	vectconteiner.clear();
	throw std::invalid_argument("Error");
}

PmergeMe::PmergeMe(char **argv)
{
	for (size_t i = 1; argv[i]; i++)
	{
		std::string str = argv[i];
		if (str.size() == 0)
			throwException();
		for (size_t j = 0; j < str.size(); j++)
			if(!isdigit(argv[i][j]))
				throwException();
		double num = static_cast<double>(atof(argv[i]));
		if (num > INT_MAX || num < 0)
			throwException();
		deqconteiner.push_back(atoi(argv[i]));
		vectconteiner.push_back(atoi(argv[i]));
	}
}

PmergeMe::~PmergeMe() {}

void PmergeMe::algorithm(void)
{
	double timeVec = 0;
	double timeDeq = 0;

	if (vectconteiner.size() <= 7)
	{
		double startTime = clock();
		insertVec(this->vectconteiner);
		double endTime = clock();
		timeVec = (endTime - startTime) * 1000 / CLOCKS_PER_SEC;

		startTime = clock();
		insertDeq(this->deqconteiner);
		endTime = clock();
		timeDeq = (endTime - startTime) * 1000 / CLOCKS_PER_SEC;
	}
	else
	{
		double startTime = clock();
		mergeVec(this->vectconteiner);
		double endTime = clock();
		timeVec = (endTime - startTime) * 1000 / CLOCKS_PER_SEC;

		startTime = clock();
		mergeDeq(this->deqconteiner);
		endTime = clock();
		timeDeq = (endTime - startTime) * 1000 / CLOCKS_PER_SEC;
	}

	std::cout << "After: ";
	this->printVec();
	std::cout << "Time to process a range of " << vectconteiner.size() \
		<< " elements with std::vector : " << timeVec << " ms" << std::endl;
	std::cout << "Time to process a range of " << deqconteiner.size() \
		<< " elements with std::deque : " << timeDeq << " ms" << std::endl;
		
}

const std::vector<int> &PmergeMe::getVec() const
{
	return vectconteiner;
}

void PmergeMe::printVec() const
{
	for (size_t i = 0; i < vectconteiner.size(); i++)
		std::cout << vectconteiner[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::insertVec(std::vector<int> &vectconteiner)
{
	for (size_t i = 0; i < vectconteiner.size(); i++) {
		size_t j = i;
		while (j > 0 && vectconteiner[j - 1] > vectconteiner[j]) {
			std::swap(vectconteiner[j], vectconteiner[j - 1]);
			j--;
		}
	}
}

void PmergeMe::mergeVec(std::vector<int> &vectconteiner)
{
	std::vector<int> leftHalf;
	std::vector<int> rightHalf;

	if (vectconteiner.size() == 1)
		return;

	size_t mid = vectconteiner.size() / 2;
	std::vector<int>::iterator midIter = vectconteiner.begin() + mid;

	leftHalf.insert(leftHalf.end(), vectconteiner.begin(), midIter);
	rightHalf.insert(rightHalf.end(), midIter, vectconteiner.end());

	mergeVec(leftHalf);
	mergeVec(rightHalf);

	vectconteiner.clear();
	std::vector<int>::iterator leftIter = leftHalf.begin();
	std::vector<int>::iterator rightIter = rightHalf.begin();

	while (leftIter != leftHalf.end() && rightIter != rightHalf.end()) {
		if (*leftIter < *rightIter)
			vectconteiner.push_back(*leftIter++);
		else
			vectconteiner.push_back(*rightIter++);
	}

	while (leftIter != leftHalf.end())
		vectconteiner.push_back(*leftIter++);

	while (rightIter != rightHalf.end())
		vectconteiner.push_back(*rightIter++);
}

const std::deque<int> &PmergeMe::getDeq() const
{
	return deqconteiner;
}

void PmergeMe::printDeq() const
{
	for (size_t i = 0; i < deqconteiner.size(); i++)
		std::cout << deqconteiner[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::insertDeq(std::deque<int> &deqconteiner)
{
	for (size_t i = 0; i < deqconteiner.size(); i++) {
		size_t j = i;
		while (j > 0 && deqconteiner[j - 1] > deqconteiner[j]) {
			std::swap(deqconteiner[j], deqconteiner[j - 1]);
			j--;
		}
	}
}

void PmergeMe::mergeDeq(std::deque<int> &deqconteiner)
{
	std::deque<int> leftHalf;
	std::deque<int> rightHalf;

	if (deqconteiner.size() == 1)
		return;

	size_t mid = deqconteiner.size() / 2;
	std::deque<int>::iterator midIter = deqconteiner.begin() + mid;

	leftHalf.insert(leftHalf.end(), deqconteiner.begin(), midIter);
	rightHalf.insert(rightHalf.end(), midIter, deqconteiner.end());

	mergeDeq(leftHalf);
	mergeDeq(rightHalf);

	deqconteiner.clear();
	std::deque<int>::iterator leftIter = leftHalf.begin();
	std::deque<int>::iterator rightIter = rightHalf.begin();

	while (leftIter != leftHalf.end() && rightIter != rightHalf.end()) {
		if (*leftIter < *rightIter)
			deqconteiner.push_back(*leftIter++);
		else
			deqconteiner.push_back(*rightIter++);
	}

	while (leftIter != leftHalf.end())
		deqconteiner.push_back(*leftIter++);

	while (rightIter != rightHalf.end())
		deqconteiner.push_back(*rightIter++);
}