#include"eJP.h"
#include<ctime>
#include<iterator>
/*simple lottery sim*/
using namespace std;

int main() {
	//variables
	srand(static_cast<uint32_t>((time(0))));
	vector<int> c;
	vector<vector<int>> z;
	map<string,int> m;
	int n, list, round = 1, balance = 0;
	char gen;	
	//choices
	cout << "How many combinations(tickets) you want to play?"; cin >> list;	
	cout << "How many rounds?"; cin >> n;
	cout << "Auto generate combinations? (y/n)"; cin >> gen;
	gen == 'y' ? genList(z, list) : manualList(z, list);
	//writeout played tickets
	cout << "Your played tickets:" << endl;
	int x = list;
	while (x) {
		ostream_iterator<int> os(cout, " ");
		copy(z[x-1].begin(), z[x - 1].end(), os);
		cout << endl;
		--x;
	}
	//price of played tickets
	cout << "Please pay " << n * list * 15 << ",00 kn" << endl;	
	cin >> balance; 
	if(balance< n * list * 15){ cout << "Not enough monney!" << endl; }
	//if balance enough
	else {
		cout << ">>>>>>>>>>ROLLING<<<<<<<<<<<<<" << endl;
		while (round <= n) {
			cout << "Round: " << round << "-> ";
			//populate vector c(draw)
			draw(c);

			//draw result writeout
			ostream_iterator<int> os(cout, " ");
			copy(c.begin(), c.end(), os);
			cout << "-->";

			//check winnings
			x = list;
			while (x) {
				rez r(cmpV(z[x - 1], c));
				winning(r, m);
				--x;
			}
			//preparation for new roud
			cout << endl;
			c.clear();
			++round;
		}
	}
	//make total winnings value and compare won->invested
	cout << "\nTotal winnings:" << endl;
	total_winnings(m);
	cout << "Payed: " << balance << " kn" << endl;
}