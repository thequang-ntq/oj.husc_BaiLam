#include <iostream>
using namespace std;

int main(){
    int n,a,b;
    int sum = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++){
        int tmp=0, tmp1=i;
        while(tmp1 > 0){
            tmp += tmp1%10;
            tmp1 /= 10;
        }
        if(a <= tmp && tmp <= b){
            sum += i;
        }
    }
    cout << sum;
}
