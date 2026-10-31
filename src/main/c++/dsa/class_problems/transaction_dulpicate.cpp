#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool hasDuplicate(const vector<string>& transactionIds) {
    unordered_set<string> seen;
    for (const string& id : transactionIds) {
        if (seen.count(id)) {
            return true;
        }
        seen.insert(id);
    }
    return false;
}