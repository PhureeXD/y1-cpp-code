#include <iostream>
#include <set>

int main() {
    std::set<int> mySet;

    mySet.insert(42);
    mySet.insert(10);
    mySet.insert(30);

    int values[] = {5, 15, 20};
    mySet.insert(values, values + 3);

    std::set<int>::iterator it = mySet.insert(42);

    if (it.second) {
        std::cout << "Successfully inserted: " << (*it).first << std::endl;
    } else {
        std::cout << "Element already exists: " << (*it).first << std::endl;
    }

    return 0;
}
