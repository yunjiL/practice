#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, K;
pair<int, int> jew[300000];
int C[300000];
priority_queue<int> pq;
long long ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> jew[i].first >> jew[i].second;

    for (int i = 0; i < K; i++)
        cin >> C[i];

    sort(jew, jew+N);
    sort(C, C+K);

    int idx = 0;
    for (int i = 0; i < K; i++)
    {
        while(idx < N && C[i] >= jew[idx].first)
            pq.push(jew[idx++].second);
        
        if (!pq.empty())
        {
            ans+=(long long)pq.top(); //자료형문제로 계속 틀림! long long 확인 필수,,
            pq.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}