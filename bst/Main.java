public class Main{
    public static void main(String Args[]){

        BinaryTree root = new BinaryTree();
        for(int i=1;i<7;i++){
            if(i%2 == 0){
                root.insert(i);
            }else{
                root.insert(i+4);
            }
        }

        root.inorder();

    }
}