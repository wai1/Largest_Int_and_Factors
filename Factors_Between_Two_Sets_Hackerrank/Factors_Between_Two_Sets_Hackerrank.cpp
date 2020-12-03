/* Largest integer of two arrays and factors.
** Author: Walter Iddings
** Date: 12/3/20
** 
** This program determines which is the largest integer in two arrays.
** It then calculates the factors of the integer and places them in the
** factors vector array. Each of those elements are tested against all
** elements in the  input arrays to determine which are either factors
** of the elements in the input arrays or the elements in the input 
** arrays are factor of the elements in the factors array.
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void getTotalX(vector<int> a, vector<int> b) {  // Return should be an int
	int largeInt = 0;
	int squareRoot = 0;
	int count = 0;  // Number of integers that satisfy the requirement
	int squareRootRounded = 0;  // Rounded down
	vector<int> factors{};  // All factors above 2 for largeInt

	// Combine the two vectors
	vector<int> temp{};
	temp.insert(temp.begin(), a.begin(), a.end());
	temp.insert(temp.end(), b.begin(), b.end());

	// Output combined vector
	cout << "The combined arrays are: ";
	for (auto i : temp) {
		cout << i << ' ';
	}

	cout << endl;

	// Find the largest int of temp vector
	largeInt = temp.at(0);
	auto it = temp.begin();  // Create & initialize iterator for combined vectors
	while (it != temp.end()) {
		if (largeInt < *it)
			largeInt = *it;
		++it;
	}
	cout << "The largest int is: " << largeInt << endl;

	// Find the square root of largeInt
	squareRoot = sqrt(largeInt);
	cout << "The square root of " << largeInt << " = " << squareRoot << endl;

	/* This step is needed only if the squareRoot variable was a float or a double.
	*  If the rounding is needed then the variable "squareRoot" in the next step 
	*  would need to be changed to "squareRootRounded"
	* 
	// Round largeInt down
	squareRootRounded = floor(squareRoot);
	cout << "largeInt rounded down is: " << squareRootRounded << endl;
	*/

	// Find all factors of squareRootRounded
	for (int i = 3; i <= squareRoot; i++) {
		if (largeInt % i == 0) {
			factors.push_back(i);
			// Check to see if there is a duplicate
			if (i == (largeInt / i))
				continue;	// There is a duplicate so do not add to factors vector
			else
				factors.push_back(largeInt / i);
		}
	}

	// Output the factors of largeInt
	cout << "The factors of largeInt are: ";
	auto it2 = factors.begin();  // Create & initialize iterator for factors of largeInt vector
	while (it2 != factors.end()) {
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	// Count the number of integers that are factors between the given vectors
	bool isFactor = false;
	it = temp.begin();  // Initialize temp vector iterator
	it2 = factors.begin();  // Initialize factors iterator
	while (it2 != factors.end()) {
		isFactor = false;  // Reset the value
		it = temp.begin();  // Initialize factors iterator
		while (it != temp.end()) {
			if (*it2 < *it) {
				if (*it % *it2 == 0)
					isFactor = true;
				else {
					break;
				}
			}
			else {
				if (*it2 % *it == 0)
					isFactor = true;
				else {
					isFactor = false;
					break;
				}
			}
			++it;
		}
		if (isFactor == true) {
			++count;
			cout << *it2 << " ";
		}
		++it2;
	}

	cout << endl;
	cout << "The number of integers satisfying the requirements is: " << count << endl;
}

int main()
{
	// Declare and initialize two vectors
	vector<int> vec1 { 2, 4 };
	vector<int> vec2 { 16, 32, 96 };

	getTotalX(vec1, vec2);
}

