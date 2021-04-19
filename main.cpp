#include "MinMaxHeap.h"

int main()
{
	vector<int> x;
	int v;
	cout << "Please input numbers: ";
	cin >> v;
	while (v != 999)
	{
		x.push_back(v);
		cin >> v;
	}
	
	cout << endl << endl;
	MinMaxHeap tree;


	char input;
	cout << "a) To build heap." << endl;
	cout << "b) To find minimum element." << endl;
	cout << "c) To find maximum element." << endl;
	cout << "d) To insert to the heap." << endl;
	cout << "e) To delete minimum element." << endl;
	cout << "f) To delete maximum element." << endl;
	cout << "g) To print the array" << endl;
	cout << "h) To end this program at anytime" << endl;

	cout << "Enter an option: ";
	cin >> input;

	while (input != 'h')
	{
		if (input == 'a')
		{
			tree.buildHeap(x);
			cout << "The heapified array is: ";
			tree.print();
		}
		else if (input == 'b')
			cout << "Minimum element is: " << tree.findMin() << endl;
		else if (input == 'c')
			cout << "Maximum element is: " << tree.findMax() << endl;
		else if (input == 'd')
		{
			int val;
			cout << "Please enter a value: ";
			cin >> val;
			tree.insertHeap(val);
		}
		else if (input == 'e')
			tree.deleteMin();
		else if (input == 'f')
			tree.deleteMax();
		else if (input == 'g')
			tree.print();

		cout << endl << endl;
		cout << "a) To build heap." << endl;
		cout << "b) To find minimum element." << endl;
		cout << "c) To find maximum element." << endl;
		cout << "d) To insert to the heap." << endl;
		cout << "e) To delete minimum element." << endl;
		cout << "f) To delete maximum element." << endl;
		cout << "g) To print the array" << endl;
		cout << "h) To end this program at anytime" << endl;
		cout << "Enter an option: ";
		cin >> input;
	}

	return 0;
}