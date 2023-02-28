# Huffman
bitio.cc is the implementation of the bitio.hh class that lets you read or write individual bytes from a file.
huffman.cc creates a huffman tree and either encodes or decodes symbols based on adaptive Huffman coding
endoder.cc takes filename as a command-line argument. It reads and compresses the file into an output file of
the same name with a .comp suffix.
decoder.cc takes in a filename, reads it, and decompressed it into a file with 
the same name and a .plaintext suffix. 

# Compression tests 
|File name|Raw file size|Compressed file size|Exact match|
|---|---|---|--- | 
|poem|364|368|yes| 
|art|1030|330|yes|
|beemovie|13486|8154 | yes|
|source.txt| 21093|13818|yes|
|alphabet.txt|77|201|yes|

# Getting Started

Download the Huffman file, Unzip it and place it somewhere easy to get to from your terminal

### Prerequisites

An basic understanding of using terminal

### Installing and Building

Download the files, use make file to compile, run ./encoder (filename) to compress and ./decoder (filename).comp to decompress
# Design Choices
Due to an incredbily thorough description of the Huffman class, all design choices in huffman followed the description.
Encoder and decoder similarly followed the thorough code example for the most part. In decoder we removed the outer loop from the example and instead of breaking when we reach the EOF, we simply end the loop when EOF is hit. Encoder was a derevation of decoder.
## BitIO
The constructor for this class takes exactly one non-null pointer to a stream: either for output or for input. A BitIO object is meant to be used either for reading from a file or writing to one, not both at once. Therefore, one of the two stream pointers passed to the constructor must be nullptr. It should save this pointer for subsequent I/O. The destructor cleans up any pending file operations.

Then, if it's an input object, you may call input_bit that returns a single boolean: the next bit from the stream (true means a bit value 1, false means 0). That result was exstracted from a buffer between the stream and the user. Then useing the bitset logical statement (buffer_ & 1<<index_) which in english means if there is a 1 at current index in buffer retuern true.

Similarly, an output object takes a single boolean bit and outputs it to its stream. It dose this by filling a buffer from index 0 to index 7 with bits. The bits in the buffer are set with the boolean logical statement buffer_ |= (bit<<index_) which means set the bit in buffer at index to bit's least signifigant digit(1 or 0 depending on if bit is true or fales).
## Huffman

# Authors

* **Becca Luff** - *Initial work* - [BeccaLuff](https://github.com/BeccaLuff)
* **Devin Arrants** - *Initial work* - [DevinArrants](https://github.com/DevinArrants)

