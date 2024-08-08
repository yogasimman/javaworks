import java.util.Scanner;

public class problem2{
    static double multiply(double first,double second,double... args){
        //minimun two numbers are required to muliply
        double product = first * second;
        for(double num: args){
            product *= num;
        }
        return product;
    }
    public static void main(String[] args) {
        double result1 = multiply(1.5, 2.0);
        System.out.println("Result 1: " + result1); // Output: 3.0

        double result2 = multiply(4.5, 2.0, 3.0);
        System.out.println("Result 2: " + result2); // Output: 27.0

        double result3 = multiply(3, 7);
        System.out.println("Result 3: " + result3); // Output: 21.0

        double result4 = multiply(5, 2.5, 4);
        System.out.println("Result 4: " + result4); // Output: 50.0
    }
}