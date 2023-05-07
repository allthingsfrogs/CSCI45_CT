#include <iostream>
#include <ctime>
using namespace std;

extern "C" {
//	int function_one(unsigned char *in, unsigned char *out, size_t width, size_t height);
//	int function_two(int *arr, size_t n, unsigned int stride);
//}

	int function_one(unsigned char *in, unsigned char *out, size_t width, size_t height) {
		int arr_size = width * height;
		for (int i = 0; i < arr_size; i++) {
			out[i] = 42;
			if (i % 2 == 0 and i % 3 == 0) out[i] = 69;
			if (i % 5 == 0) out[i] = 21;
		}
		return *out;
	}	

	int function_two(int *arr, size_t n, unsigned int stride) {
		for (size_t i = 0; i <= n; i++) {
			arr[i] = i * 3;
		}
		return *arr;
	}

//*/
}

int main(int argc, char **argv) {
	int retval;
	cout << "We have " << argc << " command line parameter(s)\n";
	cout << "Parameters are:\n";
	for (int i = 0; i < argc; i++) {
		cout << "Argument " << i << ": " << argv[i] << endl;
	}

	//YOU: Create an array here
	unsigned char array_1[13] = {21,42,42,42,42,21,69,42,42,42,21,42,69};
	unsigned char array_1_out[13]; 

	int array_2[13] = {1,3,5,7,9,11,13,15,17,19,21,23,25};
	size_t array_2_size = 13;

	//OR... use a highres timer
	//Calling the assembly function like this
	clock_t start_time = clock();
	retval = function_one(array_1, array_1_out, 13, 1);
	clock_t end_time = clock();
	cout << "Running time for function_one: " << end_time - start_time << " ticks\n";
	cout << "function_one returned: " << retval << endl;

	start_time = clock();
	retval = function_two(array_2, array_2_size, 1);
	end_time = clock();
	cout << "Running time for function_one: " << end_time - start_time << " ticks\n";
	cout << "function_one returned: " << retval << endl;
}
