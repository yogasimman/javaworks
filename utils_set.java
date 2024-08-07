import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
import java.util.LinkedList;

public class utils_set {
    public static void main(String[] args) {
        Set<String> names = new HashSet<>();
        // Set() is an abstraction, HashSet is an implementation of Set
        names.add("Walter");
        names.add("Jesse");
        names.add("Skyler");
        
        for (String name:names){
            System.out.print(name+" ");
        }

        names.forEach(System.out::println);
        Iterator<String> namesIterator = names.iterator();
        while(namesIterator.hasNext()){
            System.out.println(namesIterator);
            System.out.println(namesIterator.next());
        }
        //add() remove()
        //contains() isEmpty() 

        LinkedList<Integer> list = new LinkedList<Integer>();
        for(int i=0;i<10;i++){
            list.add(i);
        }
        System.out.println(list);

        Set<Integer> numberSet = new HashSet<>();
        //TreeSet<>() LinkedHashSet<>()
        numberSet.addAll(list);
        System.out.println(numberSet);

    }
}
