#include <vector>
#include <iostream>
#include <random>


bool proof(const std::vector<int> &arr);
bool rnd_sort(std::vector<int>& array);
int  main(){



	std::vector<int> arr = { 2,3,48,14,1,4,23131,5,15155,552760};

	if(rnd_sort(arr)) {
		std::cout << "Sorted array: ";
		for (const auto& elem : arr) {
			std::cout << elem << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}


bool rnd_sort(std::vector<int>& array) {
	int n = array.size() - 1;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, n);

	while (!proof(array)) {
		for (size_t i = 0; i < array.size(); ++i) {
			int random_number = distrib(gen);
			std::swap(array[i], array[random_number]);
		}
	}
	return true;
}


bool proof( const std::vector<int> &arr) {

	for (size_t i = 0; i < arr.size()-1; i++)
	{

		if (!(arr[i] <= arr[i + 1])) {
			
			return false;

		}
	}

	return true;
}