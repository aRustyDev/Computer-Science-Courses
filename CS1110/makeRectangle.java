# CS1110_HW1_Problem1
//makeRectangle



class rectangle {
    double width;
    double height;
    double area;
    double perimeter;

    //no-arg constructor
    public void rectangle(){
        height = 1;
        width = 1;
        area = height * width;
        perimeter = 2*(height+width);
        
        System.out.println("Rectangle Height: " + height);
        System.out.println("Rectangle Width: " + width);
        System.out.println("Rectangle Area: " + area);
        System.out.println("Rectangle Perimeter: " + perimeter);
    }

    //constructor
    public rectangle(double newHeight, double newWidth){
        height = newHeight;
        width = newWidth;
        area = height * width;
        perimeter = 2*(height+width);

        System.out.println("Rectangle ");
        System.out.println("__________");
        System.out.println("Height: " + height);
        System.out.println("Width: " + width);
        System.out.println("Area: " + area);
        System.out.println("Perimeter: " + perimeter);
        System.out.println(" ");

    }

    //Methods for perimeter and area
    void getPerimeter(double newHeight, double newWidth){
        height = newHeight;
        width = newWidth;
        double perimeter = 2*(height+width);
    }

    void getArea(double newHeight, double newWidth){
        height = newHeight;
        width = newWidth;
        double area = height * width;

    }
}


public class makeRectangle{
    public static void main(String[] args) {

        rectangle A;
        A = new rectangle(40, 4);

        rectangle B;
        A = new rectangle(3.5, 39.5);

    }//end main
}
