public class LinkedList{
    Node head;

    public void insert(int data){
        Node node = new Node();
        node.data = data;
        node.next = null;

        if(head == null){
            head = node;
        }else{
            Node n = head;
            while(n.next != null){
                n = head.next;
            }
            n.next = node;
        }
    }

    public void show(){
        Node n = head;
        System.out.print("\n[");
        while(n != null){
            System.out.print(n.data + " ");
            n = n.next;
        }
        System.out.println("]");
    }
}