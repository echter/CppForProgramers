#include "set.hpp"

// Empty set
Set::Set() {
  entries = {

  };
}

Set::Set(std::vector<int> vec) : entries(vec) {
}

Set Set::operator+(Set &otherSet) const {
  std::set<int> unionEntries;
  for (auto &val : entries) {
    if (unionEntries.find(val) == unionEntries.end()) {
      unionEntries.insert(val);
    }
  }
  for (auto &val : otherSet.getEntries()) {
    if (unionEntries.find(val) == unionEntries.end()) {
      unionEntries.insert(val);
    }
  }
  vector<int> newEntries(unionEntries.begin(), unionEntries.end());
  Set newSet(newEntries);
  return newSet;
}

// Add element
Set Set::operator+(int &val) const {

  std::set<int> values(entries.begin(), entries.end());
  if (values.find(val) == values.end())
    values.insert(val);
  vector<int> newEntries(values.begin(), values.end());
  Set set(newEntries);
  return set;
}
// Assign set to other set.
void Set::operator=(Set &set) {
  entries = set.getEntries();
}