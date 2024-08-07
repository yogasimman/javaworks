import java.util.LinkedList;
import java.util.ArrayList;

public class utils_ll{
    public static void main(String[] args){
        LinkedList<String> cars = new LinkedList<String>();
        cars.add("Jauguar");
        cars.add("Land Rover");
        System.out.println(cars);
        cars.add("Ford");
        System.out.println(cars);
        cars.set(cars.indexOf("Ford"),"Benz");
        //lastIndexof() coming from the end
        System.out.println(cars);
        cars.clear();
        System.out.println(cars);

        ArrayList<String> cars2 = new ArrayList<String>();
        //add(),get();
        cars2.add("BMW");
        cars2.set(0,"Opel");
        System.out.println(cars2.size());
        String array[] = cars.toArray();
        cars2.clear();
        System.out.println(cars2);
        System.out.println(array);

    }
}

//get() get using the index to get value
//adds at the end 
//addFirst(),addLast();
//getFirst(),getLast();
//removeFirst(),removeLast();