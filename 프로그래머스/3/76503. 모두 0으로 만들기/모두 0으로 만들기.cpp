#include <bits/stdc++.h>
using namespace std;

int degree[300001];
bool visited[300001];
vector<int> nodes[300001];

long long solution(vector<int> A, vector<vector<int>> edges) {
    long long ans = 0, sum = 0;
    vector<long long> a;
    
    for(int i = 0; i < A.size(); i++) {
        sum += A[i];
        a.push_back(A[i]);
    }
    
    if(sum != 0) return -1;

    for(int i = 0; i < edges.size(); i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        degree[a]++;
        degree[b]++;

        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    queue<int> q;
    
    for(int i = 0; i < a.size(); i++) {        
        if(degree[i] == 1) {
            degree[i]--;
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        visited[cur] = true;

        for(int i = 0; i < nodes[cur].size(); i++) {
            int next = nodes[cur][i];

            if(visited[next]) continue;

            degree[next]--;
            a[next] += a[cur];
            ans += abs(a[cur]);
            a[cur] = 0;

            if(degree[next] == 1)
                q.push(next);
        }
    }

    return ans;
}