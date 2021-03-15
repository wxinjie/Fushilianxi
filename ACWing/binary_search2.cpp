#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	double x;
	scanf("%lf",&x);
	double l = 0, r = x;
	while(r - l > 1e-6){
		double mid = (l + r) / 2;
		if(mid * mid >= x) r = mid;
		else l = mid;
	}
	printf("%.4lf",l);
	return 0;
}
