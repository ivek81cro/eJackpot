#include"eJP.h"


void izvlacenje(std::vector<int>& c) {
	std::vector<int>::const_iterator it;
	for (int i = 0; i < 7; ++i) {
		if (i < 5) { //prvih 5 brojeva
			int b = rand() % 50 + 1;
			//ne unos duplih
			it = find(c.begin(), c.end(), b);
			if (it == c.end())
				c.push_back(b);
			else
				--i;
		}
		else { //zadnja 2 broja
			int b = rand() % 10 + 1;
			it = find(c.begin() + 5, c.end(), b);
			if (it == c.end())
				c.push_back(b);
			else
				--i;
		}
	}
}
void genList(std::vector<std::vector<int>>& z, int n) {
	while (n) {
		std::vector<int> c;
		izvlacenje(c);
		sort(c.begin(), c.end() - 2);
		sort(c.begin() + 5, c.end());
		z.push_back(c);
		--n;
	}
}
void unosList(std::vector<std::vector<int>>& z, int n) {
	while (n) {
		std::vector<int> c;
		std::cout << "Listic " << n << std::endl;
		for (int i = 0; i < 7; ++i) {
			int a;
			if (i < 5)
				std::cout << "Unesite broj 1-50:";
			if (i >= 5)
				std::cout << "Unesite broj 1-10:";
			std::cin >> a;
			c.push_back(a);
		}
		sort(c.begin(), c.end() - 2);
		sort(c.begin() + 5, c.end());
		z.push_back(c);
		--n;
	}
}

// funkcija za provjeru listica
rez cmpV(const std::vector<int>& a, std::vector<int>& c) {
	rez r;
	sort(c.begin(), c.end() - 2);
	sort(c.begin() + 5, c.end());
	for (int i = 0; i < int(c.size()); ++i) {
		if (i < 5 && a[i] == c[i])
			++r.a;
		if (i >= 5 && a[i] == c[i])
			++r.b;
	}
	return r;
}
//unos dobitaka u mapu
void dobitak(const rez& r, std::map<std::string, int>& m) {
	if (r.a == 2 && r.b == 1) m["2+1"]++;//2+1
	else if (r.a == 1 && r.b == 2) m["1+2"]++;//1+2
	else if (r.a == 3 && r.b == 0) m["3+0"]++;//3+0
	else if (r.a == 3 && r.b == 1) m["3+1"]++;//3+1
	else if (r.a == 2 && r.b == 2) m["2+2"]++;//2+2
	else if (r.a == 3 && r.b == 2) m["3+2"]++;//3+2
	else if (r.a == 4 && r.b == 0) m["4+0"]++;//4+0
	else if (r.a == 4 && r.b == 1) m["4+1"]++;//4+1
	else if (r.a == 4 && r.b == 2) m["4+2"]++;//4+2
	else if (r.a == 5 && r.b == 0) m["5+0"]++;//5+0
	else if (r.a == 5 && r.b == 1) m["5+1"]++;//5+1
	else if (r.a == 5 && r.b == 2) m["5+2"]++;//5+2
}
void ispis_mape(const std::map<std::string,int> m) {
	for (auto it = m.begin(); it != m.end(); ++it)
		std::cout << it->first << ':' << it->second << std::endl;
}
