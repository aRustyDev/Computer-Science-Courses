#ifndef rectangleType_H
#define rectangleType_H

using namespace std;

class rectangleType{
public:
    void setDimension(double l, double w);
    //Function to set the length and width of the rectangle.
    //Postcondition: length = l; width = w;

    void setLength(double l);
    //Function to return the length of the rectangle.
    //Postcondition: The value of length is set.

    void setWidth(double w);
    //Function to return the width of the rectangle.
    //Postcondition: The value of width is set.

    double getLength() const;
    //Function to return the length of the rectangle.
    //Postcondition: The value of length is returned.

    double getWidth() const;
    //Function to return the width of the rectangle.
    //Postcondition: The value of width is returned.

    double area() const;
    //Function to return the area of the rectangle.
    //Postcondition: The area of the rectangle is
    //               calculated and returned.

    double perimeter() const;
    //Function to return the perimeter of the rectangle.
    //Postcondition: The perimeter of the rectangle is
    //               calculated and returned.

    void print() const;
    //Function to output the length and width of
    //the rectangle.

    rectangleType();
    //Default constructor
    //Postcondition: length = 0; width = 0;

    rectangleType(double l, double w);
    //Constructor with parameters
    //Postcondition: length = l; width = w;

    rectangleType doubleDimensions();
    //Postcondition: length = 2 * length;
    //               width = 2 * width;

private:
    double length;
    double width;
};

rectangleType rectangleType::doubleDimensions(){
    length = 2 * length;
    width = 2 * width;

    return *this;
}
void rectangleType::setDimension(double l, double w){
    if (l >= 0)
        length = l;
    else
        length = 0;

    if (w >= 0)
        width = w;
    else
        width = 0;
}
void rectangleType::setLength(double l){
    length = l;
}
void rectangleType::setWidth(double w){
    width = w;
}
double rectangleType::getLength() const{
    return length;
}
double rectangleType::getWidth()const{
    return width;
}
double rectangleType::area() const{
    return length * width;
}
double rectangleType::perimeter() const{
    return 2 * (length + width);
}
void rectangleType::print() const{
    cout << "Length = "  << length
         << "; Width = " << width;
}
rectangleType::rectangleType(double l, double w){
    setDimension(l, w);
}
rectangleType::rectangleType(){
    length = 0;
    width = 0;
}

#endif
