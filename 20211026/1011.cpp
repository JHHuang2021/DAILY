#include <bits/stdc++.h>

using namespace std;

int main() {
    int BinarySearch(int a[], int head, int tail, int search);
    string room;
    int n, k, head = 0, cnt = 0, ans = 6e4, avail = 0;
    int avail_room[100005] = {0};
    cin >> n >> k >> room;
    for (int i = 0; i < n; i++)
        if (room[i] == '0') {
            avail_room[avail] = i;
            avail++;
        }
    while (head < avail - k) {
        int mid = (avail_room[head] + avail_room[head + k]) / 2;
        int search = BinarySearch(avail_room, head, head + k, mid);
        if (mid - avail_room[search] < avail_room[search + 1] - mid)
            ans = min(ans, max(avail_room[search] - avail_room[head], avail_room[head + k] - avail_room[search]));
        else
            ans = min(ans, max(avail_room[search + 1] - avail_room[head], avail_room[head + k] - avail_room[search + 1]));
        head++;
    }
    cout << ans << endl;
    return 0;
}

int BinarySearch(int a[], int head, int tail, int search) {
    int mid = (head + tail) / 2;
    if (a[mid] == search)
        return mid;
    if (head + 1 == tail && a[head] < search && a[tail] > search)//TOBECHECKED number_of_cows=1
        return head;
    if (a[mid] < search)
        return BinarySearch(a, mid, tail, search);
    else
        return BinarySearch(a, head, mid, search);
}