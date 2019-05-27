# Project 2B - Morse Code Encoder/Decoder

## Summary 

Morse code is a common code that is used to encode messages consisting of letters and digits.  
Each letter consists of a series of dots and dashes,   
_for example..._  

| Character        | Morse           |
| ------------- |:-------------:| 
| a      | •- |
| b      | -••• |

[Project Guide Lines][Project Guide Lines]

**Member Responsibilities**

	Adam: (Team Leader)
    	Proj2_Guidelines.md
    	Proj2_README.md
    	Project 2 Wiki 
    	Code Reviewer
    	Individual Report
    	Proj2_BinSrchTreeBldr.cpp
    	Main.cpp
    
	David: 
    	Tree Building Algorithm Design
    	Project Report
    	Individual Report
    	Algorthim Efficiency
    	Proj2_Encoder.cpp
	
	Brad:    
    	UML Design  
    	Individual Report 
    	Proj2_FileReader.cpp  
    	Proj2_Decoder .cpp
	

## Objectives
+ Store each letter of the alphabet in a node of a binary tree of depth 4.  
  + The root node is at depth 0 and stores no letter.  
  + The left node at depth 1 stores the letter e (code •) 
  + The right node at depth 1 stores the letter t (code is -).  
  + The four nodes at depth 2 store the letters with codes (••,•-, -•, --). 
  
+ To build the tree...
  + Read a file, in which, each line consists of a letter followed by its code.  
    (_The letters should be ordered by tree depth_.) 
    
+ To find the position for a letter in the tree...
  + Scan the code and branch left for a dot and branch right for a dash. 
  
+ Encode a message by replacing each letter by its code symbol. 

+ Then decode the message using Morse code tree.  
  *Make sure you use a delimiter symbol between coded letters.*
  
![alt text][Tree]

## Facts and Assumptions
+ Assume that the character delimiters are simply spaces.

+ Assume the string has one word only.

+ Assume to use the source code on Blackboard  
  + [Binary_Tree][Binary_Tree]  
  + [Binary_Search_Tree][Binary_Search_Tree]
  
+ You may call the decode and encode functions in the main function.  
  There is no need for getting input from the user or a menu-based system.

## Technical Requirements

+ **(Weight: 40%)** Write a function that builds the morse tree shown in the figure above.

  + The information of the tree (the letters and the codes) is stored in a file. 
  + You can find the file here: [DropBox][Instructor_Provided_Dropbox]  
    (*Notice that the file hasn’t been laid out in convenient order for building the tree*).

+ **(Weight: 30%)** Your system should be able to decode a message using the morse tree that you built.  
_For example..._
  + Decoding -•• --• results in “dg”.   
    (_Notice that between the symbols (dots and dashes) is a space._)  
    (_The space is a delimiter that separates the codes for letters._)  

+ **(Weight: 30%)** Your system should also encode a message. 
  _For example..._ 
  + Encoding “ac” results in •- -•-•.
    
+ **NOTE:** _You may use a binary search tree or a map to store the codes for letters._

## Resources (Need Links)

[Resources File](https://github.com/RedGrinGrumbler/Comp-Sci-303-Spr19/blob/master/Proj2_Sources%26References.md)  
Morse Code Table  
Code Refereces  
Inspiration References  

[Tree]: https://github.com/RedGrinGrumbler/Comp-Sci-303-Spr19/blob/master/Proj2_ResourceFile_TreeImg.png "Tree Example"
[Binary_Tree]: https://github.com/RedGrinGrumbler/Comp-Sci-303-Spr19/blob/master/Proj2_ResourceFile_TreeImg.png "BAD LINK"
[Binary_Search_Tree]: https://github.com/RedGrinGrumbler/Comp-Sci-303-Spr19/blob/master/Proj2_ResourceFile_TreeImg.png "BAD LINK"
[Instructor_Provided_Dropbox]: https://www.dropbox.com/s/3cj8yb8gcdsrefg/morse.txt?dl=0
[Project Guide Lines]: https://github.com/RedGrinGrumbler/Comp-Sci-303-Spr19/blob/master/Proj2_Guidelines.md
