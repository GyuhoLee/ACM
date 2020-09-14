#include <bits/stdc++.h>
#define N 200001
#define SW 1
using namespace std;
typedef long long ll;
ll n, cnt, p1, p2, mx = 0;
const double PI = acos(-1);
struct point {
    ll x, y;
    bool operator<(const point& r)const {
        return x < r.x || (x == r.x && y < r.y);
    }
    ll ccw(point p, point q) { // ���� ����
        return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x);
    }
} a[N], convex[N];
void convexhull() {
    scanf("%lld", &n);
    ll i;
    for (i = 1;i <= n;i++)
        scanf("%lld %lld", &a[i].x, &a[i].y);
    // sort O(nlogn)
    sort(a + 1, a + 1 + n);
    //convexhull O(n)
    // convex�� ���ϴٰ����� ������ ��ǥ�� �����Ѵ�.
    for (i = 1;i <= n;i++) {
        for (;cnt >= 2 && convex[cnt - 1].ccw(convex[cnt], a[i]) <= 0;--cnt);
        convex[++cnt] = a[i];
    }
    for (p2 = cnt, i = n - 1;i >= 1;--i) {
        for (;cnt >= p2 + 1 && convex[cnt - 1].ccw(convex[cnt], a[i]) <= 0;--cnt);
        convex[++cnt] = a[i];
    }
    // cnt�� ���� ���� ������ ����
    p1 = 1;cnt--;
}
ll cal_dis() {
    // ���� �ٰ��� �� �� ������ �Ÿ����ϱ�
    return abs(convex[p1].x - convex[p2].x) + abs(convex[p1].y - convex[p2].y);
}
void rotating_calipers()
{
    ll i;
    ll x1, y1, x2, y2, xx1, yy1, xx2, yy2;
    double cos1, cos2;

    // x1�� y1�� ���� Ķ���۽��� ����, x2�� y2�� ������ Ķ���۽��� ����
    x1 = x2 = 0;
    y1 = -1, y2 = 1;
    //p1�� �ʱ⿡ ���ʿ� �ִ� Ķ���۽��� ���ϴٰ����� �����ִ� ��, p2�� �����ʿ� �ִ� Ķ���۽��� �ٰ����� �����ִ� ��

    for (i = 1;i <= cnt;i++) {
        mx = max(mx, cal_dis());
        //�ٰ����� ���� ������ xx1,yy1,xx2,yy2�� ���Ѵ�.
        xx1 = (convex[p1 % cnt + 1].x - convex[p1].x);yy1 = (convex[p1 % cnt + 1].y - convex[p1].y);
        xx2 = (convex[p2 % cnt + 1].x - convex[p2].x);yy2 = (convex[p2 % cnt + 1].y - convex[p2].y);

        //������ �������� �� ���� ���̰��� �ڻ����� ���Ѵ�.
        // ������ �׻� 180�� �̸��̹Ƿ� ���� ���� ���� �ڻ��� ���� ũ��.
        cos1 = (double)(x1 * xx1 + y1 * yy1) / sqrt(x1 * x1 + y1 * y1) / sqrt(xx1 * xx1 + yy1 * yy1);
        cos2 = (double)(x2 * xx2 + y2 * yy2) / sqrt(x2 * x2 + y2 * y2) / sqrt(xx2 * xx2 + yy2 * yy2);

        if (cos1 > cos2) {// cos�� �Ǽ� ������ ���ְ� ������ �纯 �����ؼ� ��� �ϸ� �ȴ�.

            //���� Ķ���۽��� ���� �ٰ����� �����ִ� ��(p1)��  �ݽð��  �ϳ� �̵� ��Ű��
            // �ٰ��� ���� ���Ͱ� Ķ���۽��� ���Ͱ� �ȴ�.
            p1 = p1 % cnt + 1;
            x1 = xx1;y1 = yy1;

            // ������ Ķ���۽��� ���� Ķ���۽��� ���⸸ �ݴ�� ����
            x2 = -x1;y2 = -y1;
        }
        else {

            //������ Ķ���۽��� ���� �ٰ����� �����ִ� ��(p2)��  �ݽð��  �ϳ� �̵� ��Ű��
               // �ٰ��� ���� ���Ͱ� Ķ���۽��� ���Ͱ� �ȴ�.
            p2 = p2 % cnt + 1;
            x2 = xx2;y2 = yy2;
            x1 = -x2;y1 = -y2;
        }
    }
    printf("%lld\n", mx);
}
int main() {
    convexhull();
    rotating_calipers();
}