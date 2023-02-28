//implementation of a class that lets you write or read individual bits from 
//an actual file. 
#include "bitio.hh"
#include <cassert>
#include <bitset>
//takes one non null pointer to a stream
//one fo teh pointers passed must be nullptr
//constructor will save this pointer for subsequent I/O
BitIO::BitIO(std::ostream* os, std::istream* is){
      os_ = os;
      is_ = is;
      assert( (os || is) && !(os && is));
      index_ = 0;
      if(os_){buffer_ = 0;}       //If Output stream create clean buffer
      else{(*is_).get(buffer_);}  //If Input stream load first buffer
}
BitIO::~BitIO(){
    if(os_ && index_!=0){
       (*os_).put(buffer_); //Save any remaining bits in buffer from BitIO::output_bit
    }
}
//takes a single boolean and outputs bit
void BitIO::output_bit(bool bit){
        if(os_){
            buffer_ |= (bit<<index_); //Sets bit at indext to 1 if bit is true
            ++index_;                 //Updats index
            if(index_ == 8){          //When the buffer is full
                    (*os_).put(buffer_); //Save the buffer
                    index_ = 0;          //Update index to beging 
                    buffer_ = 0;         //and clean the buffer
            }
        }
        else{
            std::cerr<<"This Bitio was provided an input stream"<<"\n";
            return false;
        }


}

//returns true if next bit is of value 1
//returns false if next bit is of value 0
bool BitIO::input_bit(){
  if(is_){
    bool result = (buffer_ & 1<<index_)!=0; //Sets restult to true if buffer has a 1 at index 
    index_++;//Updates index
    if(index_ == 8){  //If buffer is finished    
      (*is_).get(buffer_);  //Get next buffer
      index_=0;             //Update index
    }
    return result;
  }
  else{
    std::cerr<<"This Bitio was provided an output stream"<<"\n";
    return false;
  }
}
