#ifndef ATNODE_H_
#define ATNODE_H_
#include <sstream>

/** A node for an anagram Tree. */
struct ATNode {    // Data Fields
    char letter = '-1';
    std::string remaining_letters;
    int num_children;
    //stores child nodes
    ATNode *children;
	// Constructor
    ATNode() {}

    ATNode(const std::string word, int letter_pos) : num_children(word.size() - 1), letter(word[letter_pos]) {

        if (word.size() > 0) {
            if (word.size() == 1) {
                remaining_letters = "";
            } else {
                remaining_letters = removeLetter(letter_pos, word);
            }
        }

        children = new ATNode[word.size()];
        if (remaining_letters.size() > 0) {
            for (int i = 0; i < num_children; i++) {
                children[i] = ATNode(remaining_letters, i);
            }
        } else {
            children = nullptr;
        }
    }
	// Destructor (to avoid warning message)
    virtual ~ATNode() {}
	// to_string
	virtual std::string to_string() const {
		std::ostringstream os;
        os << letter;
		return os.str();
	}


    std::string removeLetter(int pos, std::string word) {
        if (pos == 0) {
            return word.substr(1, word.npos);
        } else if (pos == word.npos) {
            return word.substr(0, word.npos - 1);
        } else {
            return word.substr(0, pos) + word.substr(pos + 1, word.npos - pos - 1);
        }
    }

    //TODO make it find grams
    std::string *findAnagrams() {

    }
}; // End BTNode
// Overloading the ostream insertion operator
template<typename Item_Type>
std::ostream& operator<<(std::ostream& out,
                         const ATNode &node) {
		return out << node.to_string();
}


#endif
