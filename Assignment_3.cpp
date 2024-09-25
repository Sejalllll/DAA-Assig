#include<iostream>
#include<algorithm>
using namespace std;

struct shop {
    int start, end;
};

bool compare(shop a, shop b) {
    // This function is used to sort the shops based on their end times
    return a.end < b.end;
}

int maxShopsVisited(int S[], int E[], int N, int K) {
    shop shops[N];
    for (int i = 0; i < N; i++) {
        // Initialize the shops array with the start and end times
        shops[i].start = S[i];
        shops[i].end = E[i];
    }

    // Sort the shops based on their end times
    sort(shops, shops + N, compare);

    int count = 0, lastEnd = -1;
    for (int i = 0; i < N && count < K; i++) {
        // Check if the current shop can be visited by the current person
        if (shops[i].start >= lastEnd) {
            count++;
            lastEnd = shops[i].end;
        }
    }

    // Return the maximum number of shops that can be visited by K persons
    return count;
}

int main() {
    int S[] = {1, 8, 3, 2, 6};
    int E[] = {5, 10, 6, 5, 9};
    int N = sizeof(S) / sizeof(S[0]);
    int K = 2;

    cout << "Maximum number of shops visited: " << maxShopsVisited(S, E, N, K) << endl;

    return 0;
}