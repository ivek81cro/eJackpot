#ifndef eJP_H
#define eJP_H
#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

class rez {
	int a, b;
public:
	rez(int a = 0, int b = 0) :a(a), b(b) {}
	rez(const rez& r) :a(r.a), b(r.b) {
		std::cout << r.a << '+' << r.b << ' ';
	}
	friend void dobitak(const rez& r, std::map<std::string, int>& m);
	friend rez cmpV(const std::vector<int>& a, std::vector<int>& c);
};

void izvlacenje(std::vector<int>& c);
void genList(std::vector<std::vector<int>>& z, int n);
void unosList(std::vector<std::vector<int>>& z, int n);
void ispis_mape(const std::map<std::string, int> m);
rez cmpV(const std::vector<int>& a, std::vector<int>& c);
void dobitak(const rez& r, std::map<std::string, int>& m);

#endif