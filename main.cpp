#include <iostream>
#include <fstream>
using namespace std;

int find(int array[], int size, int num) { //finds the index of the specific value
	for (int i = 0; i < size; i++) {
		if (array[i] == num) {
			return i; //returns the value
		}
	}
}

int modValue(int array[], int index, int num) { //changes the value in the array
	if (index < 0 || index >= 100) {
		throw out_of_range("Index out of range."); //throws out of range error
	}
	int oldNum = array[index];
	return oldNum; //returns the old value
}
void add(int array[], int& size, int num) { //adds a value to the array
	if (size < 100) {
		array[size++] = num;
		cout << "Integer added to array.\n";
	}
	else {
		throw overflow_error("Integer could not be added to array.\n"); //throws overflow error
	}
}

void replaceArray(int array[], int& size, int index, bool toRemove) { //replaces or removes value in array
	if (index < size && index >= 0) {
		if (toRemove) { //if the user wants to remove
			for (int i = index; i < size - 1; i++) {
				array[i] = array[i + 1];
			}
			size--;
		}
		else { //if the user wants to change the value to 0
			array[index] = 0;
		}
	}
	else {
		throw out_of_range("Index out of range."); //throws the out of range error
	}
}


int main() {
	int array[100];
	int size = 0;
	ifstream file("text.txt");
	if (!file.is_open()) { //makes sure the file opens
		cerr << "Unable to open the input file.\n";
		return 1;
	}
	while (file >> array[size] && size < 100) { //sets the size of the array
		size++;
	}
	file.close(); //closes file

	try { //try and catch blocks
		
		int num = 75;
		int index = find(array, size, num);

		if (index != -1) {
			cout << "Number " << num << " found at index " << index << ".\n";
		}
		else {
			cout << "Number " << num << " not found in the array.\n";
		}

		int indexMod = 4;
		int newValue = 68;
		try { //tries the modify value function
			int oldVal = modValue(array, indexMod, newValue);
			cout << "Old Value: " << oldVal << " New Value: " << newValue << "\n";
		}
		catch (const out_of_range& e) { //catches the error in modVal function
			cerr << "Error modifying value: " << e.what() << "\n";
		}
		
		int newInt = 168;
		try { //tries the add function
			add(array, size, newInt);
		}
		catch (const overflow_error& e) { //catches the error in the add function
			cerr << "Error adding integer: " << e.what() << "\n";
		}
		
	}
	catch (const exception& e) {
		cerr << "An unexpected error occurred: " << e.what() << "\n";
	}
}