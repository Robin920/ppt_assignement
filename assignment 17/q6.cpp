#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    // Sort the deck in ascending order
    sort(deck.begin(), deck.end());

    int n = deck.size();
    deque<int> indices;

    // Initialize the indices with the positions from 0 to n-1
    for (int i = 0; i < n; i++) {
        indices.push_back(i);
    }

    vector<int> result(n);

    // Perform the card revealing process
    for (int card : deck) {
        result[indices.front()] = card;
        indices.pop_front();
        if (!indices.empty()) {
            indices.push_back(indices.front());
            indices.pop_front();
        }
    }

    return result;
}

int main() {
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> result = deckRevealedIncreasing(deck);

    cout << "The ordering of the deck to reveal the cards in increasing order is: ";
    for (int card : result) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}
