#include <iostream>
using namespace std;
template <int N> struct poly { double data[N + 1]; };

template <int N>
ostream& operator << (ostream& output, const poly<N> &p) {
	int i = 0;
	for (i = N; i >=0 ; i--)
	{
		if (i>0 ) 
		{
			if(i!=N+1)
			{
				if ((p.data[i] > 0)&(i<N-1)) 
				{
					output << "+";
				}
			}
			if (p.data[i] != 0) 
			{
				output << p.data[i] << "*x^" << i;
			}
		}
		else if (p.data[i] != 0)
		{
			if (p.data[i] > 0)
			output << "+";
			output << p.data[i];
		}
	}
	return output;
}

template <int N>
poly<N-1> differentiate(poly<N> p)
{
	poly<N - 1> f;
	for (int i = N; i >= 1; i--)
	{
		if (i > 0)
		{
			f.data[i-1] = p.data[i] * i;
		}

	}
	return f;
}

template<int N>
poly<N> operator+(poly<N> p, double d)
{
	p.data[0] += d;
	return p;
}
int main()
{
	poly<4> p = { -1,4,-3,2 };
	cout << (p+100)<<endl;
	cout << (p) << endl;
	cout << differentiate(p);

}

