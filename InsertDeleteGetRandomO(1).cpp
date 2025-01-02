#include <algorithm>
#include <cstdlib>
using namespace std;
class RandomizedSet {
private:
    vector<int> set;
    unordered_map<int, int> indices;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(indices.find(val) != indices.end()) {
            return false; 
        }
        set.push_back(val);
        indices[val] = set.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        auto it = indices.find(val);
        if(it == indices.end()) {
            return false; 
        }
        int index = it->second;
        int lastElement = set.back();

        set[index] = lastElement;
        indices[lastElement] = index;

        set.pop_back();
        indices.erase(val);

        return true;
    }
    
    int getRandom() {
        int max = set.size();
        return set[rand() % max];
    }
};
