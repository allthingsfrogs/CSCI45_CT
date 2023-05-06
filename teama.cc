#include <iostream>
#include <ctime>
using namespace std;

extern "C" {
	int function_one(unsigned char *in, unsigned char *out, size_t width, size_t height);
	int function_two(int *arr, size_t n, unsigned int stride);
}

int main(int argc, char **argv) {
//	int retval;
//	cout << "We have " << argc << " command line parameter(s)\n";
//	cout << "Parameters are:\n";
//	for (int i = 0; i < argc; i++) {
//		cout << "Argument " << i << ": " << argv[i] << endl;
//	}

	//YOU: Create an array here
	int size = 25;
	int pooperscooper[size] = {21,420,420,420,21,69,420,420,420,21,420,69,420,420,21,420,420,69,420,21,420,420,420,69};

	for (int i = 0; i < size; i++) {
		pooperscooper[i] = 420;
		if (i % 2 == 0 and i % 3 == 0) pooperscooper[i] = 69;
		if (i % 5 == 0) pooperscooper[i] = 21;
	}
	for (int i = 0; i < size; i++) cout << pooperscooper[i] << endl;



	//OR... use a highres timer
	//Calling the assembly function like this
	clock_t start_time = clock();
	//retval = function_one(...);
	clock_t end_time = clock();
	cout << "Running time for function_one: " << end_time - start_time << " ticks\n";
//	cout << "function_one returned: " << retval << endl;

	start_time = clock();
	//retval = function_two(...);
	end_time = clock();
	cout << "Running time for function_one: " << end_time - start_time << " ticks\n";
//	cout << "function_one returned: " << retval << endl;
}
