// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>


using namespace std;


double P0(const int N, const int G)
{
	double P = 1;
	for (int K = N; K <= G; K++)
		P *= sqrt(1 + ((N * 1.0) / K));
	return P;
}


double P1(const int N, const int G, const int K)
{
	if (K > G)
		return 1;
	else
		return sqrt(1 + ((N * 1.0) / K)) * P1(N, G, K + 1);

}
double P2(const int N, const int K)
{
	if (K < N)
		return 1;
	else
		return sqrt(1 + ((N * 1.0) / K)) * P2(N, K-1);
}


double P3(const int G, const int N, const int K, double t)
{
	t = t * sqrt(1 + ((N * 1.0) / K));
	if (K >= G)
		return t;
	else
		return P3(G, N, K + 1, t);
}


double P4(const int N, const int K, double t)
{
	t = t * sqrt(1 + ((N * 1.0) / K));
	if (K <= N)
		return t;
	else
		return P4(N, K - 1, t);
}


int main()
{
	int N;

	cout << "N = "; cin >> N;

	int G = 25;

	cout << "(iter)            P0 = " << P0(N, G) << endl;
	cout << "(rec up ++)       P1 = " << P1(N, G, N) << endl;
	cout << "(rec up --)       P2 = " << P2(N, G) << endl;
	cout << "(rec down ++)     P3 = " << P3(G, N, N, 1) << endl;
	cout << "(rec down --)     P4 = " << P4(N, G, 1) << endl;

	return 0;
}
