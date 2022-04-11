// C++ code to demonstrate the working of
// operator() function

#include <iostream>

// for uniform_int_distribution function
#include <random>

using namespace std;
default_random_engine generator;

int random_p()
{
	// Here default_random_engine object
	// is used as source of randomness
	// We can give seed also to default_random_engine
	// if psuedorandom numbers are required


	int a = 0, b = 9;

	// Initializing of uniform_int_distribution class
	uniform_int_distribution<int> distribution(a, b);

	// number of experiments
	const int num_of_exp = 10;

	int n = b - a + 1;
	int p[n] = {};
	for (int i = 0; i < num_of_exp; ++i) {

		// using operator() function
		// to give random values
		cout << distribution(generator) << endl;
      
	}
    cout << "end" << endl;
	// cout << "Expected probability: "
	// 	<< float(1) / float(n) << endl;

	// cout << "uniform_int_distribution ("
	// 	<< a << ", " << b << ")" << endl;

	// // Displaying the probability of each number
	// // after generating values 10000 times.
	// for (int i = 0; i < n; ++i)
	// 	cout << a + i << ": "
	// 		<< (float)p[i] / (float)(num_of_exp)
	// 		<< endl;

	return 0;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int j = random_p();
    }
    return 0;
}