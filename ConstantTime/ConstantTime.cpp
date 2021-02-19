// ConstantTime class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

/***********************************************
ConstantTime class

Contains an unordered set of value T defined by
object and performs insertion, deletion, and
search requests on these values.

***********************************************/
template <class T>
class ConstantTime {
private:
	unordered_map<T, int> constMap;
	vector<T> constVec;
public:
	void insertItem(T x);
	void deleteItem(T x);
	T searchItem(T x);
	T getRandom();
};

template <class T>
void doObjWork(ConstantTime<T>& a);

int main()
{
	srand((unsigned)time(NULL));
	ConstantTime<int> intObj;
	ConstantTime<double> doubObj;
	ConstantTime<char> charObj;
	int choice;

	do
	{
		cout << "Which object would you like to run tests for?\n";
		cout << "1) Int\n";
		cout << "2) Double\n";
		cout << "3) Char\n";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			doObjWork(intObj);
			break;
		}
		case 2: {
			doObjWork(doubObj);
			break;
		}
		case 3: {
			doObjWork(charObj);
			break;
		}
		case 4: {
			break;
		}
		default:
			cout << "Not an accepted choice. Please try again.\n";
		}

	} while (choice != 4);

	return 0;
}

template <class T>
void ConstantTime<T>::insertItem(T x) {
	if (constMap.find(x) == constMap.end()) {
		constMap.insert(make_pair(x, constVec.size()));
		constVec.push_back(x);
	}
	else
		cout << "Item " << x << " already exists in set.\n";
}

template <class T>
void ConstantTime<T>::deleteItem(T x) {
	if (!constMap.empty()) {
		if (constMap.find(x) != constMap.end()) {
			cout << "Found " << constMap.find(x)->first << " at position " << constMap.find(x)->second << endl;
			int pos = constMap.find(x)->second;
			constMap.erase(x);
			swap(constVec[pos], constVec[constVec.size() - 1]);

			T newKey = constVec[pos];
			constVec.pop_back();

			if (constMap.find(newKey) != constMap.end()) {
				constMap.find(newKey)->second = pos;
			}

		}
		else
			cout << "Item " << x << " could not be found.\n";
	}
}

template <class T>
T ConstantTime<T>::searchItem(T x) {
	if (!constMap.empty()) {
		if (constMap.find(x) != constMap.end()) {
			cout << "Found ";
			return x;
		}

		else
			cout << "Item " << x << " could not be found.\n";
	}
	return -1;
}

template <class T>
T ConstantTime<T>::getRandom() {

	int randIdx = rand() % (constVec.size() - 1);

	cout << "Value of random index " << randIdx << " is ";
	return constVec[randIdx];
};

template <class T>
void doObjWork(ConstantTime<T>& a) {

	T item;
	cout << "Add 10 items\n";
	for (int i = 0; i < 10; i++)
	{
		if (!(cin >> item))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			a.insertItem(item);
		}
	}

	cout << "\nRemove 3 items\n";

	for (int i = 0; i < 3; i++) {

		if (!(cin >> item))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			a.deleteItem(item);
	}

	cout << "\nSearch 3 items\n";

	for (int i = 0; i < 3; i++) {

		if (!(cin >> item)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			cout << a.searchItem(item) << endl;
	}

	cout << a.getRandom() << endl;
	cout << a.getRandom() << endl;
}