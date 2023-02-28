/*
 * HForest: is a collection of independent HTreees.
 * HTrees: each HTree in the collection is the root of its own tree.
 */
#include "htree.hh"
#include <algorithm>
#include <vector>

class HForest{
 public:
    //Constructs a Forest of size 0
    HForest();
    //Destructor
    ~HForest() = default;
    //Returns size of forest
    int size() const;
    //Adds a tree to the forrest
    void add_tree(HTree::tree_ptr_t tree);
    // Finds Tree with the highest value in the root node,
    // removes it from the forest, and returns a pointer to it
    HTree::tree_ptr_t pop_tree();


private:
    std::vector<HTree::tree_ptr_t> trees_;// The Tree pointers
};

//Returns True if value of t1 is greater than value of t2
bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2);

