#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string findBook(const vector<pair<string, string>>& catalog, const string& targetIsbn) {
    int left = 0;
    int right = catalog.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (catalog[mid].first == targetIsbn) {
            return catalog[mid].second;
        } else if (catalog[mid].first < targetIsbn) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return "Not Found";
}