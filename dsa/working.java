public class working {
    public static void main(String args[]){
        queue stk = new queue(10);
        stk.enqueue(5);
        stk.enqueue(6);
        stk.enqueue(2);
        stk.enqueue(1);
        stk.dequeue();
        stk.dequeue();
        stk.dequeue();
        stk.dequeue();
        stk.dequeue();
        stk.display();
    }
}
