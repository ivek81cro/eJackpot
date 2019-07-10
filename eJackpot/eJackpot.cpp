#include"eJP.h"
#include<ctime>
#include<iterator>

/*simple lottery sim*/
using namespace std;

int main() {
	srand(static_cast<uint32_t>((time(0))));
	vector<int> c;
	map<string,int> m;
	int n, list, kolo=1, stanje;
	char gen;
	cout << "How many combinations(tickets) you want to play?"; cin >> list;
	vector<vector<int>> z;
	cout << "How many rounds?"; cin >> n;
	cout << "Auto generate combinations? (y/n)"; cin >> gen;
	gen == 'y' ? genList(z, list) : unosList(z, list);
	cout << "Your played tickets:" << endl;
	int x = list;
	while (x) {
		ostream_iterator<int> os(cout, " ");
		copy(z[x-1].begin(), z[x - 1].end(), os);
		cout << endl;
		--x;
	}
	cout << "Please pay " << n * list * 15 << ",00 kn" << endl;
	cin >> stanje;
	cout << ">>>>>>>>>>ROLLING<<<<<<<<<<<<<" << endl;
	while (kolo<=n) {
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
			rez r(cmpV(z[x-1], c));
			dobitak(r, m);
			--x;
		}

		cout << endl;
		c.clear();
		++kolo;
	}
	cout << "\nTotal winnings:" << endl;
	ispis_mape(m);
}