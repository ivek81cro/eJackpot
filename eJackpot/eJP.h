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
	friend void winning(const rez& r, std::map<std::string, int>& m);
	friend rez cmpV(const std::vector<int>& a, std::vector<int>& c);
};

void draw(std::vector<int>& c);
void genList(std::vector<std::vector<int>>& z, int n);
void manualList(std::vector<std::vector<int>>& z, int n);
void total_winnings(const std::map<std::string, int> m);
void winning(const rez& r, std::map<std::string, int>& m);
rez cmpV(const std::vector<int>& a, std::vector<int>& c);

#endif