#include <unordered_map>

class Node {
public:
    std::string name;
    std::unordered_map<std::string, float> neighbors;

    Node(const std::string& name) : name(name) {}
};
