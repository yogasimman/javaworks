public class working {
    public static void main(String args[]){
        priority_queue stk = new priority_queue(10);
        stk.push(6);
        stk.push(7);
        stk.push(8);
        stk.push(1);
        stk.push(9);
        stk.pop();
        stk.display();
    }
}
