#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class MinMaxHeap
{
private:
	vector<int> array;
	int size; //size of array

public:
	MinMaxHeap() :size(1) { array.push_back(NULL);};
	void buildHeap(vector<int> nums);
	int findMin();
	int findMax();
	void insertHeap(int num);
	void deleteMin();
	void deleteMax();

public: //helper functions
	void TrickleDownMin(int& i);
	void TrickleDownMax(int& i);
	int parentInd(int val);
	int leftInd(int val);
	int rightInd(int val);
	void pushUpMin(int i);
	void pushUpMax(int i);
	void print()
	{
		for (int i = 1; i < size; i++)
		{

			cout << array[i] << " ";
		}
	}

};


