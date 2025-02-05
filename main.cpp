#include <cstdio>

int a;

void f(int &b) {
    a = 3;
    b = b*a;
}

int main() {
    a = 2;
    f(a);
    printf("%d", a);
    return 0;
}