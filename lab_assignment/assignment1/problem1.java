import java.util.Scanner;
import java.util.HashSet;

public class problem1{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        final byte inputs = 5;
        //boolean,char,int,short,byte,long,float,double
        byte array[] = new byte[inputs];
        System.out.println("Enter 5 numbers:");

        //read
        for(int i=0;i<5;i++){
            System.out.print("Enter Number" + (i+1) + ":");
            array[i] = scanner.nextByte();
        }

        //display
        HashSet<Byte> duplicate = new HashSet<Byte>();
        System.out.print("\nUnique numbers: ");
        boolean worst_case = true;
        for(int i=0;i<5;i++){
            if(duplicate.add(array[i])){
                System.out.print(array[i] + ",");
            }else{
                worst_case = false;
            }
        }
        System.out.print("\n");
        if(worst_case){
            System.out.println("Worst Case");
        }
        System.out.print("\n");
        scanner.close();
    }
}