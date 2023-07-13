#include <iostream>
#include <cmath>
using namespace std;

double Bisect(double, double, double, int);

int main()
{
	 Bisect(0, 0.11, 0.00, 5);
}

double Bisect(double a, double b, double provided_error, int max_iteration) //Method to solve convergence problems using bisection
{
	double estimated_root, old_est_root, estimated_error; //variables for the root, root swapping  and estimated error
	int iteration_counter = 0; //Variable to keep track of iterations
	double fa, fb, test; //function f(a), f(b), and the test to see if the function can be solved using bisection
	
	cout << "a = "<< a << "\nb = " << b << "\n\n\n ***first iteration***"<< endl;
	estimated_root = a;
	//fa = (2 * a) - (3 * sin(a)) - 5; // 2x - 3sinx - 5
	fa = pow(a,3) - (0.165 * pow(a,2)) + 0.0003993; //x3 (x cube) - 0.165x2 (squared) + 0.0003993
	
	
	do
	{
		iteration_counter++; 
		cout << "Iteration " << iteration_counter << endl;
		old_est_root = estimated_root; //swap old root with new root to initialize the program
		
		estimated_root = (a + b)/2; // find the midpoint 
		
		fb = pow(estimated_root, 3) - (3 * pow(estimated_root,2)) + 0.0003993;
		//fb = (2 * estimated_root) - (3 * sin(estimated_root)) - 5;
		//fb = pow(estimated_root, 3) - (3*estimated_root) + 1;
		cout << "c = "<< estimated_root << endl;
		if (iteration_counter != max_iteration) cout << "f(c) = " << fb << endl << endl;
		
		
		if (estimated_root != 0)
		{
			estimated_error = abs((estimated_root - old_est_root)/estimated_root); //estimated error 
		}
		
		test = fa * fb; // bisection method only works if the signs of f(a) and f(b) are different 
		if (test < 0)
		b = estimated_root;
		
		else if (test > 0) //if the signs are the same i.e +, + or -, - stop the function/use different boundary
		{
			a = estimated_root;	
			fa = fb;
		}
		
		else estimated_error = 0;
		
	} while (/*estimated_error > provided_error &&*/ iteration_counter < max_iteration);
	
	return estimated_root;
}

