#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, sq=0, rec=0, tri=0;
		cin >> n;
		if (n%4==0) sq++;
		if (n%2==0) {
			rec = n/2 - ceil((float)n/4) - sq;
		}
		for (int a=1; a<=n/3; a++){
			for (int b=a; n-a-b>=b; b++){
				int c = n-a-b;
				if (a+b > c && a+c>b && b+c>a) tri++;
			}
		}
		cout << "Triangles: " << tri;
		cout << "\nSquares: " << sq;
		cout << "\nRectangles: " << rec;
		cout << endl;
	}
	return 0;
}
