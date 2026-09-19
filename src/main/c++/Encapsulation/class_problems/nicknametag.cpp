#include <iostream>
#include <string>

class NameTag {
private:
    const std::string firstName;
    const char lastInitial;

public:
    NameTag(const std::string& fullName) 
        : firstName(extractFirstName(fullName)), 
          lastInitial(extractLastInitial(fullName)) {}

    std::string getNickname() const {
        return firstName + " " + lastInitial + ".";
    }

private:
    static std::string extractFirstName(const std::string& name) {
        size_t spacePos = name.find(' ');
        if (spacePos != std::string::npos) {
            return name.substr(0, spacePos);
        }
        return name;
    }

    static char extractLastInitial(const std::string& name) {
        size_t spacePos = name.find(' ');
        if (spacePos != std::string::npos && spacePos + 1 < name.length()) {
            return name[spacePos + 1];
        }
        return '\0'; 
    }
};

// Usage Example
void testNameTag() {
    NameTag tag("Maria Gomez");
    std::cout << "Nickname: " << tag.getNickname() << "\n"; // Maria G.
}