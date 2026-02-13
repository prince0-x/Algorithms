#include <bits/stdc++.h>
using namespace std;
// priincce system design style coding 
bool solv(const string &pots) {
    int totalPots = pots.size();
    vector<int> emptyPotIndices;
    for (int index = 0; index < totalPots; ++index) {
        if (pots[index] == '0') emptyPotIndices.push_back(index);
    }
    if (emptyPotIndices.empty()) return true;
    vector<bool> canLookLeft(totalPots, false);
    vector<bool> canLookRight(totalPots, false);
    for (int index : emptyPotIndices) {
        canLookLeft[index] = (index == 0) || (pots[index - 1] == '0') || 
                             (index >= 2 && pots[index - 1] == '1' && pots[index - 2] == '0');

        canLookRight[index] = (index == totalPots - 1) || (pots[index + 1] == '0') || 
                              (index + 2 < totalPots && pots[index + 1] == '1' && pots[index + 2] == '0');
    }
    int currentIndex = 0;
    int totalEmptyPots = emptyPotIndices.size();
    while (currentIndex < totalEmptyPots) {
        int nextIndex = currentIndex;
        while (nextIndex + 1 < totalEmptyPots &&
               emptyPotIndices[nextIndex + 1] == emptyPotIndices[nextIndex] + 2 &&
               pots[emptyPotIndices[nextIndex] + 1] == '1') {
            ++nextIndex;
        }
        int firstEmptyPot = emptyPotIndices[currentIndex];
        int stateMask = (canLookLeft[firstEmptyPot] ? 1 : 0) | (canLookRight[firstEmptyPot] ? 2 : 0);
        if (stateMask == 0) return false;
        for (int potIndex = currentIndex + 1; potIndex <= nextIndex; ++potIndex) {
            int currentEmptyPot = emptyPotIndices[potIndex];
            int nextStateMask = 0;
            if ((stateMask & 1) && canLookRight[currentEmptyPot]) nextStateMask |= 2;
            if ((stateMask & 2) && canLookLeft[currentEmptyPot]) nextStateMask |= 1;
            stateMask = nextStateMask;
            if (stateMask == 0) return false;
        }
        currentIndex = nextIndex + 1;
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        int numberOfPots;
        string potArrangement;
        cin >> numberOfPots >> potArrangement;
        cout << (solv(potArrangement) ? "YES\n" : "NO\n");
    }
    return 0;
}
