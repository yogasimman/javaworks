import java.util.HashMap;

public class utils_map{
        public static void main(String[] args){
            //Map is an interface
            //HashMap -> implementation of Map
            HashMap<String,Integer> empIds = new HashMap<>();
            empIds.put("Yogas",446);
            empIds.put("Carl",3563);
            empIds.put("jerry",3353);
            System.out.println(empIds);

            System.out.println(empIds.get("Carl"));
            System.out.println(empIds.containsKey("George"));
            System.out.println(empIds.containsValue(446));
            empIds.put("Yogas",777);
            System.out.println(empIds);
            empIds.putIfAbsent("Yogas",333);
            System.out.println(empIds);

            empIds.replace("jerry",233);
            System.out.println(empIds);
        }
    
}