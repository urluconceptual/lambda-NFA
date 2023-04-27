#include <iostream>
#include <cstring>

using namespace std;

	int nr_nod, tranz, si, nr_sf, nr_cuvinte, nr_nod1, nr_nod2, sf[500] = { 0 }, ok, traseu[500], stare;
	char cuvant[500], litera, cuv[500][500];
	char automat[500][500];


int Solutie(int k, int lit) {
	if (lit == strlen(cuvant) - 1 && sf[traseu[k]] == 1)
		return 1;
	else
		return 0;
}

int OK(int k, int lit) {
	if (k == 0) {
		if (traseu[k] == si)
			return 1;
		else return 0;
	}
	else
		if (automat[traseu[k - 1]][traseu[k]] == cuvant[lit])
			return 1;
		else
			if (automat[traseu[k - 1]][traseu[k]] == '#')
				return 1;
			else
				return 0;
}

void Afisare(int k)
{
	cout << "DA" << endl << "Traseu: ";
	for (int i = 0; i <= k; i++)
		cout << traseu[i] << " ";
	cout << endl;
	ok = 1;
}

void test(int k, int lit) {
	for (int i = 0; i <= nr_nod; ++i)
	{
		traseu[k] = i;
		if (OK(k, lit))
			if (Solutie(k, lit))
				Afisare(k);
			else
				if (automat[traseu[k - 1]][traseu[k]] == '#')
					test(k + 1, lit);
				else
					test(k + 1, lit+1);
	}

}

int main()
{

	cin >> nr_nod >> tranz;
	for (int i = 0; i < tranz; i++) {
		cin >> nr_nod1 >> nr_nod2 >> litera;
		automat[nr_nod1][nr_nod2] = litera;
	}
	cin >> si >> nr_sf;
	for (int i = 0; i < nr_sf; i++) {
		int j;
		cin >> j;
		sf[j] = 1;
	}
	cin >> nr_cuvinte;
	for (int i = 0; i < nr_cuvinte; i++) {
		cin >> cuv[i];
	}
	for (int i = 0; i < nr_cuvinte; i++) {
		strcpy_s(cuvant, cuv[i]);
		ok = 0;
		test(0, -1);
		if (ok == 0) {
		cout << "NU" << endl;
	}
	}
}
