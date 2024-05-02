// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

template <class T>
T sum(T* foo, T S, T v)
{
    T ans = 0;
    for(int i  = 0;i < S;i++)
        ans += foo[i];
    
    return ans;
}

template <class T>
T abs_sum(T* foo, T S, T v)
{
    T ans = 0;
    for(int i  = 0;i < S;i++)
        ans += abs(foo[i]);
    
    return ans;
}

template <class T>
T product(T* foo, T S, T v)
{
    //if(S == 0) return 0;
    
    T ans = v;
    for(int i  = 0;i < S;i++)
        ans *= foo[i];
    
    return ans;
}

template <class T>
T compute(T (*fn)(T*, T, T),T* foo, T& S, T& v)
{
    return fn(foo,S,v);
}


int main() {    
    // 請勿更動main()函式裡的程式碼
    // Please do not modify the code inside the main() function.
    int foo[10];
    int S;
    cin >> S;
    for(int i = 0; i < S; i++) cin >> foo[i];
    int v;
    v = 0;
    cout << compute(sum<int>, foo, S, v) << endl;
    v = 0;
    cout << compute(abs_sum<int>, foo, S, v) << endl;
    v = 1;
    cout << compute(product<int>, foo, S, v) << endl;
    return 0;
}
