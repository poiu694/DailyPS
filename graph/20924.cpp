#include <iostream>
#include <vector>

using namespace std;

int N, rootNode;
int gigaNode = 0;
int rootSum = 0; int leafSum = 0;
bool visited[200001];
vector<pair<int, int>> tree[200001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> rootNode;

    int node, child, value;
    for (int i = 0; i < N - 1; i++) {
        cin >> node >> child >> value;

        tree[node].push_back({ child, value });
        tree[child].push_back({ node, value });
    }
}

void calRoot(int node) {
    if (node == rootNode && tree[node].size() >= 2) {
        gigaNode = node;
        return;
    }

    if (tree[node].size() > 2) {
        gigaNode = node;
        return;
    }

    visited[node] = true;

    for (int i = 0; i < tree[node].size(); i++) {
        int nextNode = tree[node][i].first;

        if (!visited[nextNode]) {
            rootSum += tree[node][i].second;
            gigaNode = nextNode;
            calRoot(nextNode);
        }
    }
}

void calLeaf(int node, int sum) {
    if (visited[node]) {
        return;
    }

    if (sum > leafSum) {
        leafSum = sum;
    }

    visited[node] = true;
    for (int i = 0; i < tree[node].size(); i++) {
        calLeaf(tree[node][i].first, sum + tree[node][i].second);
    }
}

void solve() {
    calRoot(rootNode);
    calLeaf(gigaNode, 0);

    cout << rootSum << " " << leafSum;
}

int main() {
    init();
    input();
    solve();
}
