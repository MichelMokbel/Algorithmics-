#include <iostream>

using namespace std;

template <class T>
class X{
    public:
        T max(T a, T b){
            T pg;
            pg = (a>b) ? a : b;
            return (pg);
        };
};

int main(){
    X<int> x;
    int i = 5, j = 2, k;
    k = x.max(i,j);
    cout << k << endl;
}