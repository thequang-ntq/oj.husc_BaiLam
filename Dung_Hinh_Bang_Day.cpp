#include <bits/stdc++.h>
using namespace std;

int main(){
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        
        int cntTriangle = 0;
        int cntSquare = 0;
        int cntRectangle = 0;
        
        // count rectangle and square
        if (n % 2 == 0) {
            int k = n / 2;
            cntSquare = (k % 2 == 0);
            cntRectangle = (k - 1) / 2;
        }
        
        // count triangle 
        for (int i = 1; i <= n; i++) {
            int k = n - i;
            if (k <= i) continue;
            if (i >= k - i) cntTriangle += (i - (k - i) + 2) / 2;
        }
        
        cout << "Triangles: " << cntTriangle << "\n";
        cout << "Squares: " << cntSquare << "\n";
        cout << "Rectangles: " << cntRectangle << "\n\n";
    }
    return 0;
}
