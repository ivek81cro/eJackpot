#include"eJP.h"
#include<ctime>
#include<iterator>

/*simulacija izvlacenja 5+2 brojeva i usporedba sa dvije odabrane kombinacije
za n izvlacenja*/
using namespace std;

int main() {
	srand(static_cast<uint32_t>((time(0))));
	vector<int> c;
	map<string,int> m;
	int n, list, kolo=1, stanje;
	char gen;
	cout << "Koliko listica zelite igrati?"; cin >> list;
	vector<vector<int>> z;
	cout << "Koliko kola zelite igrati?"; cin >> n;
	cout << "Zelite li nasumicno generirane brojeve na listice? (y/n)"; cin >> gen;
	gen == 'y' ? genList(z, list) : unosList(z, list);
	cout << "Vasi odigrani listici:" << endl;
	int x = list;
	while (x) {
		ostream_iterator<int> os(cout, " ");
		copy(z[x-1].begin(), z[x - 1].end(), os);
		cout << endl;
		--x;
	}
	cout << "Molim platite " << n * list * 15 << ",00 kn" << endl;
	cin >> stanje;
	cout << ">>>>>>>>>>IZVLACENJE<<<<<<<<<<<<<" << endl;
	while (kolo<=n) {
		cout << "Kolo: " << kolo << "-> ";
		//popuna vektora c(izvlacenje brojeva)
		izvlacenje(c);

		//ispis izvucenih brojeva
		ostream_iterator<int> os(cout, " ");
		copy(c.begin(), c.end(), os);
		cout << "-->";

		//provjera dobitaka
		x = list;
		while (x) {
			rez r(cmpV(z[x-1], c));
			dobitak(r, m);
			--x;
		}

		cout << endl;
		c.clear();
		++kolo;
	}
	cout << "\nSvi dobici:" << endl;
	ispis_mape(m);
}