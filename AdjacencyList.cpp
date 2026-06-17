#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<char> vertex(N);
    map<char,int> idx;

    for (int i = 0; i < N; i++) {
        cin >> vertex[i];
        idx[vertex[i]] = i;
    }
    int M;
    cin >> M;
    vector<vector<int>> matrix(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        matrix[idx[u]][idx[v]] = w;
    }
    cout << "Adjacency Matrix:\n";
    cout << "  ";
    for (char c : vertex)
        cout << c << " ";
    cout << '\n';
    for (int i = 0; i < N; i++) {
        cout << vertex[i] << " ";
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}