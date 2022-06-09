#include <iostream>
#include <math.h>
using namespace std;

long long multiply(long long x, long long y) 
{
	int xLength = trunc(log10(x)) + 1;
	int yLength = trunc(log10(y)) + 1;

	// the bigger of the two lengths
	int N = fmax(xLength, yLength);

	// if the max length is small it's faster to just multiply the two nums
	if (N < 10)
		return x * y;

	long long multiplier = pow(10, N / 2);		// To Shift bits

	long long XL = x / multiplier;		
	long long XR = x - (XL * multiplier);
	long long YL = y / multiplier;			
	long long YR = y - (YL * multiplier);	

	long long p1 = multiply(XL, YL);
	long long p2 = multiply(XR, YR);
	long long p3 = multiply(XL + XR, YL + YR);

	return p1 * pow(10, N) + (p3 - p1 - p2) * multiplier + p2;	// By Carl Gauss's note, 4 multiplications to 3 multiplications 
}

int main() 
{
	long long a = 24069941;
	long long b = 23285631;
	cout << multiply(a, b) << endl;
	return 0;
}
