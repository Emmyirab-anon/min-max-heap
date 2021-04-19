#include "MinMaxHeap.h"
#include <cmath>

void MinMaxHeap::buildHeap(vector<int> nums)
{
	
	for (int i = 0; i < nums.size()+10; i++)
		array.push_back(NULL);

	for (int i = 0; i < nums.size(); i++)
		array[i + 1] = nums[i];

	size += nums.size();

	
	for (int i = (size/2); i > 0; i--)
	{
		if (int(log2f(i)) % 2 == 0) // min level
			TrickleDownMin(i);
		else
			TrickleDownMax(i);
	}

}

int MinMaxHeap::findMin()
{
	assert(size > 0);
	return array[1];
}

int MinMaxHeap::findMax()
{
	assert(size > 0);
	if (size == 1)
		return array[1];
	else if (size == 2)
		return array[2];
	else
		return max(array[2], array[3]);
}

void MinMaxHeap::insertHeap(int num)
{
	if (size == array.size() - 1)
		array.resize(array.size() * 2);
	size++;
	array[size - 1] = num;

	if (size - 1 != 1)
	{
		if (int(log2f(size - 1)) % 2 == 0)
		{
			if (array[size - 1] > array[parentInd(size - 1)])
			{
				swap(array[size - 1], array[parentInd(size - 1)]);
				pushUpMax(parentInd(size - 1));
			}
			else
				pushUpMin(size - 1);
		}
		else
			if (array[size - 1] < array[parentInd(size - 1)])
			{
				swap(array[size - 1], array[parentInd(size - 1)]);
				pushUpMin(parentInd(size - 1));
			}
			else
				pushUpMax(size - 1);
	}
}

void MinMaxHeap::deleteMin()
{
	if (size == 0)
		return;
	swap(array[1], array[size - 1]);
	size--;

	int x = 1;
	if (int(log2f(x)) % 2 == 0) // min level
		TrickleDownMin(x);
	else
		TrickleDownMax(x);
}

void MinMaxHeap::deleteMax()
{
	if (size == 0)
		return;
	int j = max(array[1], max(array[2],array[3]));
	int index;
	if (j == array[1])
		index = 1;
	else if (j == array[2])
		index = 2;
	else if (j == array[3])
		index = 3;

	swap(array[index], array[size - 1]);
	size--;

	if (int(log2f(index)) % 2 == 0) // min level
		TrickleDownMin(index);
	else
		TrickleDownMax(index);
}

void MinMaxHeap::pushUpMin(int i)
{
	if (parentInd(parentInd(i)) > 0 && array[i] < array[parentInd(parentInd(i))])
	{
		swap(array[i], array[parentInd(parentInd(i))]);
		pushUpMin(parentInd(parentInd(i)));
	}
}

void MinMaxHeap::pushUpMax(int i)
{
	if (parentInd(parentInd(i)) > 0 && array[i] > array[parentInd(parentInd(i))])
	{
		swap(array[i], array[parentInd(parentInd(i))]);
		pushUpMax(parentInd(parentInd(i)));
	}
}

void MinMaxHeap::TrickleDownMin(int& i)
{
	if (size > leftInd(i))
	{
		int m = leftInd(i);
		if (rightInd(i) < size && array[rightInd(i)] < array[m])
			m = rightInd(i);

		for (int j = leftInd(leftInd(i)); j <= min(rightInd(rightInd(i)), size); j++)
		{
			if (array[j] < array[m])
				m = j;
		}

		if (m >= leftInd(leftInd(i)))
		{
			if (array[m] < array[i])
			{
				swap(array[m], array[i]);
				if (array[m] > array[(m - 1) / 2])
					swap(array[m], array[(m - 1) / 2]);
				TrickleDownMin(m);
			}
		}

		else {
			if (array[m] < array[i])
				swap(array[m], array[i]);
		}

	}
}

void MinMaxHeap::TrickleDownMax(int& i)
{
	if (size > leftInd(i))
	{
		int m = leftInd(i);
		if (rightInd(i) < size && array[rightInd(i)] > array[m])
			m = rightInd(i);

		for (int j = leftInd(leftInd(i)); j <= min(rightInd(rightInd(i)), size); j++)
		{
			if (array[j] > array[m])
				m = j;
		}

		if (m >= leftInd(leftInd(i)))
		{
			if (array[m] > array[i])
			{
				swap(array[m], array[i]);
				if (array[m] < array[(m - 1) / 2])
					swap(array[m], array[(m - 1) / 2]);
				TrickleDownMin(m);
			}
		}

		else {
			if (array[m] > array[i])
				swap(array[m], array[i]);
		}

	}
}

int MinMaxHeap::parentInd(int val)
{
	if (val & 1)
		return val / 2;
	return ((val-1) / 2);
}

int MinMaxHeap::leftInd(int val)
{
	return (2 * val + 1);
}

int MinMaxHeap::rightInd(int val)
{
	return(2 * val + 2);
}