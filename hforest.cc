#include "hforest.hh"
#include <algorithm>

//this function creates heap in an ordered manner such that the first element is the least
bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2){
    return t1->get_value() > t2->get_value();
}

//Constructs a Forest of size 0
HForest::HForest(){
    std::vector<HTree::tree_ptr_t> trees_ {};
}


//Returns size
int HForest::size() const{return trees_.size();}

//adds a tree to forrest and to the heap
void HForest::add_tree(HTree::tree_ptr_t tree){trees_.push_back(tree); //adds tree to back of vector
        std::push_heap(trees_.begin(), trees_.end(), compare_trees);} //add to heap in ordered manner

//pops least tree off the heap and returns it to the user
HTree::tree_ptr_t HForest::pop_tree(){
    if(trees_.empty())          return nullptr; //check if tree is empty first
    HTree::tree_ptr_t smallest = trees_.front();
    std::pop_heap(trees_.begin(), trees_.end(), compare_trees); //pop least value off
    trees_.pop_back();
    return smallest;
}


