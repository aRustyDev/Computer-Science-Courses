/*      Title: boxType.h | Problem 13.03
 *      Author: Adam Smith | RedGrinGrumbler
 *
 *              ::Compiler Info::
 *      CMD: cpp --version
 *          Apple LLVM version 10.0.1 (clang-1001.0.46.4)
 *          Target: x86_64-apple-darwin18.6.0
 *          Thread model: posix
 *      CMD: gcc --version
 *          Apple LLVM version 10.0.1 (clang-1001.0.46.4)
 *          Target: x86_64-apple-darwin18.6.0
 *          Thread model: posix
 *
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp13
 *
 *      Purpose: Define the Class for boxType, so as to practice with overloading functions.
 *
 */

#ifndef CHP13_03_BOXTYPE_H
#define CHP13_03_BOXTYPE_H

#include <iostream>
#include "rectangleType.h"

using namespace std;

class boxType : public rectangleType
{
        //Overload Stream insert/extract Operators
        friend ostream& operator<<(ostream&, const boxType& box);
        friend istream& operator>>(istream&, boxType& box);

        //Pre-Increment/Decrement Dimensions
        //Postcondition:       length += 1;
        //                     width += 1;
        //                     depth += 1;
        boxType operator++ ();
        boxType operator-- ();

        //Post-Increment/Decrement Dimensions
        //Postcondition:       length += 1;
        //                     width += 1;
        //                     depth += 1;
        boxType operator++ (int);
        boxType operator-- (int);

    public:
        boxType();
        //Default constructor
        //Postcondition: length = 0; width = 0; depth = 0;

        boxType(double l, double w, double d);
        //Constructor with parameters
        //Postcondition: length = l; width = w;

        void setDepth(double);
        //Function to return the depth of the box.
        //Postcondition: The value of depth is set.

        double getDepth() const;
        //Function to return the depth of the box.
        //Postcondition: The value of depth is returned.

        double volume() const;
        //Function to return the area of the box
        //Postcondition: The area of the box is
        //               calculated and returned.

        void print() const;
        //Function to output the length, width, & depth of
        //the box.

        boxType doubleDimensions();
        //Postcondition: length = 2 * length;
        //               width = 2 * width;
        //               depth = 2 * depth;

        //compare volumes
        //Postcondition: a boolean value is returned
        //
        bool operator== (const boxType& otherBox) const;
        bool operator!= (const boxType& otherBox) const;
        bool operator< (const boxType& otherBox) const;
        bool operator<= (const boxType& otherBox) const;
        bool operator> (const boxType& otherBox) const;
        bool operator>= (const boxType& otherBox) const;

        //Add/Sub volumes
        //Postcondition: Box1 +/-/* Box2 = returnedBox;
        //
        boxType operator+ (const boxType& otherBox) const;
        boxType operator- (const boxType& otherBox) const;
        boxType operator* (const boxType& otherBox) const;

    private:
        double length;
        double width;
        double depth;
};
boxType::boxType(){
    length = 0;
    width = 0;
    depth = 0;
}
boxType::boxType(double l, double w, double d){
    length = l;
    width = w;
    depth = d;
}
void boxType::print() const{
    cout << "Length : "  << length
         << "\nWidth : " << width
         << "\nDepth : " << depth << endl;
}
void boxType::setDepth (double d) {
    depth = d;
}
double boxType::getDepth () const {

}
double boxType::volume() const{
    return length * width * depth;
}
boxType boxType::doubleDimensions(){
    length = 2 * length;
    width = 2 * width;
    depth = 2 * depth;
    return *this;
}
bool boxType::operator== (const boxType& otherBox) const{
    return(length == otherBox.length && width == otherBox.width && depth == otherBox.depth);
}
bool boxType::operator!= (const boxType& otherBox) const{
    return(length != otherBox.length && width != otherBox.width && depth != otherBox.depth);
}
bool boxType::operator< (const boxType& otherBox) const{
    return((length * width * depth) < (otherBox.length * otherBox.width * otherBox.depth));
}
bool boxType::operator<= (const boxType& otherBox) const{
    return((length * width * depth) <= (otherBox.length * otherBox.width * otherBox.depth));
}
bool boxType::operator> (const boxType& otherBox) const{
    return((length * width * depth) > (otherBox.length * otherBox.width * otherBox.depth));
}
bool boxType::operator>= (const boxType& otherBox) const{
    return((length * width * depth) >= (otherBox.length * otherBox.width * otherBox.depth));
}
boxType boxType::operator+ (const boxType& otherBox) const{
    double l = length + otherBox.length;
    double w = width + otherBox.width;
    double d = depth + otherBox.depth;
    return(boxType(l,w,d));
}
boxType boxType::operator- (const boxType& otherBox) const{
    double l = length - otherBox.length;
    double w = width - otherBox.width;
    double d = depth - otherBox.depth;
    return(boxType(l,w,d));
}
boxType boxType::operator* (const boxType& otherBox) const{
    double l = length * otherBox.length;
    double w = width * otherBox.width;
    double d = depth * otherBox.depth;
    return(boxType(l,w,d));
}
ostream& operator<< (ostream& osobject, const boxType& box){
    osobject << "Box Length: " << box.getLength()
             << "Box Width: " << box.getWidth()
             << "Box Depth: " << box.getDepth();
    return osobject;
}
istream& operator>> (istream& isobject, boxType& box){
    isobject >> box.getLength() >> box.getWidth() >> box.getDepth();
    return isobject;
}
boxType boxType::operator++ (){
    (this->length)++;
    (this->width)++;
    (this->depth)++;
    return *this;
}
boxType boxType::operator-- (){
    (this->length)--;
    (this->width)--;
    (this->depth)--;
    return *this;
}
boxType boxType::operator++ (int){
    boxType tmp = *this;
    length++;
    width++;
    depth++;
    return tmp;
}
boxType boxType::operator-- (int){
    boxType tmp = *this;
    length--;
    width--;
    depth--;
    return tmp;
}

#endif //CHP13_03_BOXTYPE_H
