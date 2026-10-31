#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> buildLookup(const vector<pair<string, string>>& records) {
    unordered_map<string, string> lookup;
    for (const auto& record : records) {
        lookup[record.first] = record.second;
    }
    return lookup;
}

string getDepartment(const unordered_map<string, string>& lookup, const string& employeeId) {
    auto it = lookup.find(employeeId);
    if (it != lookup.end()) {
        return it->second;
    }
    return "Unknown";
}