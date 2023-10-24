#include <fstream>
#define MAX_N 100
using namespace std;
ifstream fin("windows.in");
ofstream fout("windows.out");
struct fereastra
{
	int l1, c1, l2, c2;
};
int n, clickuri;
bool inchisa[MAX_N];
fereastra f[MAX_N];
void citesteDateIntrare();
void initializeazaVectorCaracteristic();
void inchideFereastra(int);
int main()
{
	citesteDateIntrare();
	initializeazaVectorCaracteristic();
	inchideFereastra(0);
	fout << clickuri;
	fout.close();
	return 0;
}
void initializeazaVectorCaracteristic()
{
	for (int i = 0; i < n; i++)
	{
		inchisa[i] = 0;
	}
}
void citesteDateIntrare()
{
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> f[i].l1 >> f[i].c1 >> f[i].l2 >> f[i].c2;
	}
	fin.close();
}
bool peste(int i, int j)
{
	// verifica daca fereastra f[i] este peste coltul dreapta sus al ferestrei f[j]
	if (f[i].l1 <= f[j].l1
		&& f[i].l2 >= f[j].l1
		&& f[i].c1 <= f[j].c2
		&& f[i].c2 >= f[j].c2)
	{
		return 1;
	}
	return 0;
}
void inchideFereastra(int nr)
{
	int i;
	for (i = n-1; i > nr; i--)
	{
		if (!inchisa[i] && peste(i, nr))
		{
			inchideFereastra(i);
		}
	}
	inchisa[nr] = 1;
	clickuri++;
}
// scor 100
