#include <bits/stdc++.h>
using namespace std;


int CCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int temp = x1 * y2 + x2 * y3 + x3 * y1;
    temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
    if (temp > 0) return 1;         //�ݽð����
    else if (temp < 0) return -1;   //�ð����
    else return 0;                  //������
}