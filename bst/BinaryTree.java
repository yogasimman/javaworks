class Node{
    int data;
    Node left;
    Node right;

    public Node(int data){
        this.data = data;
    }

    public Node(int data,Node left,Node right){
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

public class BinaryTree{
    Node root;

    Node insertWork(int data,Node node){
        if(node == null){
            return new Node(data);
        }

        if(node.data > data){
            node.left = insertWork(data,node.left);
        }else{
            node.right = insertWork(data,node.right);
        }
        return node;
    }

    public void insert(int data){
        root = insertWork(data,root);
    }

    int minvalue(Node node){
        while(node.left != null){
            node = node.left;
        }
        return node.data;
    }

    void inorderWork(Node node){
        if(node != null){
            inorderWork(node.left);
            System.out.print(node.data+",");
            inorderWork(node.right);
            return;
        }
       
    }

    public void inorder(){
        inorderWork(root);
    }

    Node deleteWork(int data,Node node){
        if(node != null){
            if(node.data > data){
                node.left = deleteWork(data,node.left);
            }else if (node.data < data){
                node.right = deleteWork(data,node.right);
            }

            if(node.left == null && node.right == null){
                //deletenode
                node = null;
            }else if(node.left == null){
                //deletenode
                node = node.right;
            }else if(node.right == null){
                //deletenode
                node = node.left;
            }else{
                node.data = minvalue(node.right);
                node.right = deleteWork(node.data,node.right);
            }
        }
        return node;
    }

    public void delete(int data){
        root = deleteWork(data,root);
    } 
}