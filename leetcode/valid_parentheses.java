import java.util.Stack;
class valid_parentheses {

    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<Character>();
        boolean valid = true;
        for(int i=0;i<s.length();i++){
            char a = s.charAt(i);
            char b;
            if(a == '(' || a == '{' || a == '['){
                stk.push(a);
            }else{
                if(!stk.empty()){
                    b = stk.peek();
                    if(b == '(' && a == ')'){
                        stk.pop();
                    }else if(b == '{' && a == '}'){
                        stk.pop();
                    }else if(b == '[' && a == ']'){
                        stk.pop();
                    }else{
                        return false;
                    }
                }else{
                    valid = false;
                    return valid;
                }
            }
        }
        if(!stk.empty()){
            return false;
        }
        return valid;
    }
}