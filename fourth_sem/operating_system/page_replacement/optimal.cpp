#include <bits/stdc++.h>
using namespace std;

bool search(int key, const vector<int>& fr) {
    for (int page : fr)
        if (page == key) return true;
    return false;
}

int predict(int pg[], const vector<int>& fr, int pn, int index) {
    int res = -1, farthest = index;
    for (int i = 0; i < (int)fr.size(); i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn) return i;  // Not used in future
    }
    return (res == -1) ? 0 : res;
}

void printFrames(const vector<int>& fr, int fn) {
    for (int i = 0; i < fn; i++) {
        if (i < (int)fr.size())
            cout << setw(2) << fr[i] << " ";
        else
            cout << " - ";
    }
    cout << "\n";
}

void optimalPage(int pg[], int pn, int fn) {
    vector<int> fr;
    int pageFaults = 0;

    cout << "Frames after each page request:\n";

    for (int i = 0; i < pn; i++) {
        int page = pg[i];
        bool hit = search(page, fr);

        if (!hit) {
            if ((int)fr.size() < fn)
                fr.push_back(page);
            else {
                int idx = predict(pg, fr, pn, i + 1);
                fr[idx] = page;
            }
            pageFaults++;
        }

        cout << "Page " << setw(2) << page << ": ";
        printFrames(fr, fn);
    }

    cout << "\nTotal Page Faults: " << pageFaults << "\n";
    cout << "Total Page Hits: " << pn - pageFaults << "\n";
}

int main() {
    int pg[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int pn = sizeof(pg) / sizeof(pg[0]);
    int fn = 4;

    cout << "Optimal Page Replacement Algorithm\n";
    cout << "Page Requests: ";
    for (int i = 0; i < pn; i++) cout << pg[i] << " ";
    cout << "\n\n";

    optimalPage(pg, pn, fn);

    return 0;
}
