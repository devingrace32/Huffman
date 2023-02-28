#include "bitio.hh"
#include "huffman.hh"
#include <iostream>
#include <fstream>
#include <string>
int main(int argc, char const *argv[])
{  if(argc<2){ //Make sure filename was provided
    std::cerr<<"Need input filename to encode\n";
    return -1;
  }
  
  std::ifstream inp(argv[1]); //Opens input file


  if(!inp.is_open()){ //Make sure file can be opened
    std::cerr<<"Can't open input file "<<argv[1]<<"\n";
    return -2; 
  }
   std::fstream out(std::string(argv[1])+".comp",std::ios::out); //Creats .comp file
 
   char symbol;       //Creats  symbol to send to huff for encodeing
   Huffman huff;      //Creats huff for encoding
   BitIO bitio(&out, nullptr); //Creats BitIO to save to .comp file

  while(inp.get(symbol)){
    auto bits = huff.encode(symbol);//Encodes symbol
    for(bool bit : bits){
      bitio.output_bit(bit); //Sends that code to file.comp
    }
  }

  for(auto bit: huff.encode(Huffman::HEOF)){//Encodes and attaches EOF to end of .comp file
	  bitio.output_bit(bit);
  } 
   return 0; 
} 
