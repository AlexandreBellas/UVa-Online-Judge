#include <bits/stdc++.h>
using namespace std;

#include <math.h>

int main(){
	double a, b, c;
	while(cin >> a >> b >> c){
		double p = (a + b + c)/2.0;

		double r = sqrt((p - a) * (p - b) * (p - c) / p);
		double areaCircInscrita = M_PI*(p - a)*(p - b)*(p - c)/p;
		
		double areaTriangulo = p*r;
		
		double areaCircCircunscrita;
		double raiomaior = (a * b * c)/(r * p * 4);
		areaCircCircunscrita = M_PI*raiomaior*raiomaior;
		
		areaCircCircunscrita -= areaTriangulo;
		areaTriangulo -= areaCircInscrita;

		cout << fixed << setprecision(4) << areaCircCircunscrita << " ";
		cout << fixed << setprecision(4) << areaTriangulo << " ";
		cout << fixed << setprecision(4) << areaCircInscrita << endl;
	}
	

	return 0;
}