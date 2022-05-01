#pragma once
#include<iostream>
using namespace std;
class Graf
{
	int NrNod;
	int NrMuchii;
	int a[101][101];
public:
	Graf();
	Graf(int, int, int x[][101]);
	Graf(const Graf&);
	~Graf();
	int GetNrNod();
	int GetGrad(int x);
	bool Bipartit();
	bool Hamiltonian(int v[], int n);
	void HamiltonianExist(int v[], int n);
	friend ostream& operator<<(ostream& os, Graf&);
	friend istream& operator>>(istream& is, Graf&);


};
