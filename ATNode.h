#ifndef ATNODE_H_
#define ATNODE_H_
#include <sstream>

/** A node for an anagram Tree. */
struct ATNode {    // Data Fields
    std::string letter;
    std::string remaining_letters;
    int num_children;
    //stores child nodes
    ATNode *children;
	// Constructor
    ATNode(const std::string the_data, int letter_pos) :
            remaining_letters(the_data), num_children(the_data.size()), children(new ATNode[the_data.size()]),
            letter(the_data.at(letter_pos)) {}
	// Destructor (to avoid warning message)
    virtual ~ATNode() {}
	// to_string
	virtual std::string to_string() const {
		std::ostringstream os;
        os << letter;
		return os.str();
	}
}; // End BTNode
// Overloading the ostream insertion operator
template<typename Item_Type>
std::ostream& operator<<(std::ostream& out,
                         const ATNode &node) {
		return out << node.to_string();
}

#endif
