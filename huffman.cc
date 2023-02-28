#include "huffman.hh"
#include "hforest.hh"
#include <iostream>
#include <assert.h>

HTree::tree_ptr_t Huffman::create_huff(){
    //Create one new HTree node for every possible character + EOF (257 total). 
    HForest forest;
    for(unsigned i = 0; i < freq_.size(); i++){
        //Each node will have its symbol (character) as the key, and its count 
        //from the frequency table as a value.
        std::shared_ptr<HTree> tmp(new HTree(i, Huffman::freq_[i]));
        forest.add_tree(tmp);
    }
    //Iterate until the forest has a single tree in it
    while(forest.size() > 1){
        //Find the top-two HTrees in the forest (those who have the lowest frequency count).
        auto left = forest.pop_tree();
        auto right = forest.pop_tree();
        //Merge them as the left and right nodes of a new HTree node. 
        std::shared_ptr<HTree> key(new HTree(-1, left->get_value() + right->get_value(), left, right));
        forest.add_tree(key);
    }
    return forest.pop_tree();
}

Huffman::bits_t Huffman::encode(int symbol){
    //bool vector 
    bits_t bits;
    huff_ = create_huff();
    //get path
    auto path = huff_-> path_to(symbol);
    //for direction in path, if direction is left push 1 onto bits
    for(auto dir : path){
       if(dir == HTree::Direction::RIGHT){
            bits.push_back(true);
        }
        else{
            bits.push_back(false);
        }
    }
    //increment frequency in table
    freq_[symbol]++;  
    return bits;
}

int Huffman::decode(bool bit){
    //If this is the first bit in a sequence (Huffman tree not yet computed), build a Huffman tree
    //Otherwise, start from the previous node you've computed.
    if(huff_ == nullptr)     Huffman::huff_ = Huffman::create_huff();
    //Compute the next node as either the left or right child of the current node, depending on the bit value.
    if(bit == 1)     huff_ = huff_ -> get_child(HTree::Direction::RIGHT);
    else             huff_ = huff_ -> get_child(HTree::Direction::LEFT);                
    //Eventually, the current node will be a leaf, at which point a real character c will be returned, 
    //and you can reset the Huffman tree to nullptr to remember that next bit starts a new sequence. 
    int key = huff_->get_key();
    if(key >= 0) {
	//increment frequency table for c 
        freq_[key]++;
        huff_ = nullptr;
    }     
    return key;

}

