#include <cmath>
#include <cstdio>
using namespace std;

#define gc getchar

int read()
{
    char c = gc();
    while (c == ' ' || c == '\n')
        c = gc();
    int nz = 0;
    while ('0' <= c && c <= '9')
        nz = (nz << 3) + (nz << 1) + c - 48, c = gc();
    return nz;
}

int solve(int a, int b)
{
    return a + b;
}

int main() { 
    int a;
    int b;
    
    a = read();
    b = read();
    
    int res = solve(a, b);
    
    printf("%d", res);
    
    return 0;
}
