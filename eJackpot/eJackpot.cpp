#include"eJP.h"
#include<ctime>
#include<iterator>
#include "Handler.h"
/*simple lottery sim*/
using namespace std;

int main() {
	//varijable
	srand(static_cast<uint32_t>((time(0))));
	vector<int> c;
	vector<vector<int>> z;
	map<string,int> m;
	int n, list, kolo = 1, stanje = 0;
	char gen;	
	//upiti
	cout << "How many combinations(tickets) you want to play?"; cin >> list;	
	cout << "How many rounds?"; cin >> n;
	cout << "Auto generate combinations? (y/n)"; cin >> gen;
	gen == 'y' ? genList(z, list) : unosList(z, list);
	//ispis odigranih kombinacija
	cout << "Your played tickets:" << endl;
	int x = list;
	while (x) {
		ostream_iterator<int> os(cout, " ");
		copy(z[x-1].begin(), z[x - 1].end(), os);
		cout << endl;
		--x;
	}
	//cijena odabranih kombinacija
	cout << "Please pay " << n * list * 15 << ",00 kn" << endl;	
	cin >> stanje; 
	if(stanje < n * list * 15){ cout << "Not enough monney!" << endl; }
	//ako je sve ok
	else {
		cout << ">>>>>>>>>>ROLLING<<<<<<<<<<<<<" << endl;
		while (kolo <= n) {
			cout << "Round: " << kolo << "-> ";
			//popuna vektora c(izvlacenje brojeva)
			izvlacenje(c);

			//ispis izvucenih brojeva
			ostream_iterator<int> os(cout, " ");
			copy(c.begin(), c.end(), os);
			cout << "-->";

			//provjera dobitaka
			x = list;
			while (x) {
				rez r(cmpV(z[x - 1], c));
				dobitak(r, m);
				--x;
			}
			//priprema za novo kolo
			cout << endl;
			c.clear();
			++kolo;
		}
	}
	//napraviti i novcanu vrijednost dobitaka i usporedbu ulog-gubitak
	cout << "\nTotal winnings:" << endl;
	ispis_mape(m);
	
}