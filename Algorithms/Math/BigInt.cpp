#include <iostream>
#include <vector>

using namespace std;

class BigInt 
{
friend std::ostream& operator<<(std::ostream & out, const BigInt& B)
{
	size_t size = B.A.size();
	for (int i = size - 1;i >= 0;i--)
		out << B.A[i];
	return out;
}
private:
	vector<int> A; // DSIZE = 200 digits long. May use vector<int> instead.
public:
	// Constructor
	BigInt() { };
	 // with integer
	BigInt(long num);
	 // Add
	BigInt operator+(int with);
	 // Multiplication
	 // with integer
	BigInt operator*(int with);
};

// Convert integer to big integer
BigInt::BigInt(long n)
{
	for (int i = 0;n > 0;i++)
	{
		A.push_back(n % 10);
		n /= 10;
	}
}

BigInt BigInt::operator*(int num)
{
	BigInt result;
	size_t size = A.size();
	int temp = 0;
	for (int i = 0;i < size;i++)
	{
		int x = num * A[i] + temp;
		result.A.push_back(x % 10);
		temp = x / 10;
	}

	for (int i = size;temp > 0;i++)
	{
		result.A.push_back(temp % 10);
		temp /= 10;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	const int large = (int) 1e9;
	BigInt B(1e18);
	cout << B * large << endl;
	return 0;
}
