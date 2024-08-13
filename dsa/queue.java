public class queue {
    int arr[];
    int front;
    int rear;
    int capacity;
    public queue(int n){
        arr = new int[n];
        front = rear = -1;
        capacity = n;
    }
    public boolean isfull(){
        if(rear == capacity - 1){
            return true;
        }
        return false;
    }
    public boolean isempty(){
        if(front == -1){
            return true;
        }
        return false;
    }
    public boolean enqueue(int x){
        if(!isfull()){
            arr[++rear] = x;
            if(front == -1){
                front++;
            } 
            return true;
        }
        return false;
    }
    public boolean dequeue(){
        if(!isempty()){
            front++;
            if(front == capacity){
                front = -1;
                rear = -1;
            }
            return true;
        }
        return false;
    }
    public void display(){
        if(isempty()){
            return;
        }
        System.out.print("\n[");
        for(int i=front;i<=rear;i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println("]");
    }
}
