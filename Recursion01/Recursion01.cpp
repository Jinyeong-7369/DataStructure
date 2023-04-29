#include<iostream>
#define SIZE 5
using namespace std;

int QuickRank(int a[], int start, int end, int want);
void PrintAll(int a[], int size);
void Swap(int& a, int& b);

int main(void)
{
    int a[] = { 7, 1, 2, 3, 4, 5, 1};
    int n = sizeof(a) / sizeof(int);
    int result;
    int want;
    for (int i = 0; i < n; i++)
    {
        want = i;
        result = QuickRank(a, 0, n - 1, want);
        cout << "The " << want << "th smallest element is: " << a[result] << endl;
    }
}

int QuickRank(int a[], int start, int end, int want)
{
    int pivot = a[end];
    int up = start;
    int down = end - 1;

    while (up <= down) {
        while (a[up] < pivot) up++;
        while (a[down] > pivot) down--;
        if (up < down) Swap(a[up], a[down]);
        else if (up == down) {
            if (a[up] == pivot) up++;
            break;
        }
    }
    Swap(a[up], a[end]);
    if (up == want) return up;
    else if (up > want) return QuickRank(a, start, up - 1, want);
    else return QuickRank(a, up + 1, end, want);
}

void PrintAll(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << a[i] << "]";
    }
    cout << endl;
}

void Swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}