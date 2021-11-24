#include <bits/stdc++.h>

using namespace std;

int main() {
    void PrintTriangle(char a, char b, int m);
    void PrintSquare(char a, int m);
    void PrintRhombus(char a, char b, int m);
    string shape;
    char a, b;
    int m;
    cin >> shape >> a >> b >> m;
    if (shape == "Triangle")
        PrintTriangle(a, b, m);
    if (shape == "Square")
        PrintSquare(a, m);
    if (shape == "Rhombus")
        PrintRhombus(a, b, m);
    return 0;
}

void PrintTriangle(char a, char b, int m) {
    for (int i = 1; i <= (m + 1) / 2; i++) {
        for (int j = (m - 2 * i + 1) / 2; j >= 1; j--)
            printf("%c", b);
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("%c", a);
        for (int j = (m - 2 * i + 1) / 2; j >= 1; j--)
            printf("%c", b);
        printf("\n");
    }
}

void PrintSquare(char a, int m) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++)
            printf("%c", a);
        printf("\n");
    }
}

void PrintRhombus(char a, char b, int m) {
    for (int i = 1; i <= (m + 1) / 2; i++) {
        for (int j = (m - 2 * i + 1) / 2; j >= 1; j--)
            printf("%c", b);
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("%c", a);
        for (int j = (m - 2 * i + 1) / 2; j >= 1; j--)
            printf("%c", b);
        printf("\n");
    }
    for (int i = (m + 1) / 2 - 1; i >= 1; i--) {
        for (int j = (m - 2 * i + 1) / 2; j >= 1; j--)
            printf("%c", b);
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("%c", a);
        for (int j = (m - 2 * i + 1) / 2; j >= 1; j--)
            printf("%c", b);
        printf("\n");
    }
}