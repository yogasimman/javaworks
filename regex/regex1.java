import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class regex1{
    public static void main(String args[]){
        Pattern p = Pattern.compile("[a-zA-Z][a-zA-Z0-9]*[@][a-z]+[.a-z]+");
        String input = "example@domain.co.in";
        Matcher m = p.matcher(input);

        if(m.matches()){
            System.out.println("Valid email");
        }else{
            System.out.println("Not a valid email");
        }
    }
}