#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, len[1000], cache[1000][1000];

/*
���� col��° ������ �� ���̰� cur�� �ܾ �̹� ���� ��
���� �ܾ ��� ���� ���� �� �ִ� ���� ������ �� �ּڰ�
*/
int minSquareSum(int col, int cur) {
	// ���� ���: ��� �ܾ �� ��
	if (cur == N) return 0;
	// �ش� ���� �� ä�� ���ų� �� ĭ�� ���� ���
	if (col >= M) return minSquareSum(len[cur] + 1, cur + 1) + (col == M ? 1 : 0);
	int& ret = cache[col][cur];
	if (ret != -1) return ret;

	// ���� �ٷ� �Ű� ���鼭 ���� ������ ĭ�� ������ ����
	ret = minSquareSum(len[cur] + 1, cur + 1) + (M - col + 1) * (M - col + 1);
	// �ش� �ٿ� �̾ �� �� ���� ���
	if (col + len[cur] <= M) ret = min(ret, minSquareSum(col + len[cur] + 1, cur + 1));
	return ret;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", len + i);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", minSquareSum(len[0] + 1, 1));
}