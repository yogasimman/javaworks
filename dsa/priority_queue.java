public class priority_queue {
    int arr[];
    int capacity;
    int pointer;
    public priority_queue(int x){
        arr = new int[x];
        capacity = x;
        pointer = -1;
    }
    public boolean isfull(){
        return capacity-1 == pointer?true:false;
    }
    public boolean isempty(){
        return pointer == -1?true:false;
    }
    public boolean push(int x){
        if(!isfull()){

            arr[++pointer] = x;
            int index = pointer;
            int parent;
            int temp;

            while(index > 0){
                parent = (index % 2 == 0)?(index/2)-1:index/2;
                if(arr[parent] > arr[index]){
                    //swapping the variable
                    temp = arr[index];
                    arr[index] = arr[parent];
                    arr[parent] = temp;
                    //looping
                    index = parent;
                    continue;
                }else{
                    break;
                }
            }
            return true;
        }
        return false;
    }

    public int pop(){
        if(!isempty()){
            int result = arr[0];
            arr[0] = arr[pointer--];

            int index = 0,child1,child2,smallerchild;
            int temp;

            while(index <= pointer){
                child1 = (2*index) + 1;
                child2 = (2*index) + 2;
                if(child1 <= pointer){
                    if(child2 <= pointer){
                        smallerchild = (arr[child1] < arr[child2])?child1:child2;
                    }else{
                        smallerchild = child1;
                    }

                    if(arr[index] > arr[smallerchild]){
                        temp = arr[index];
                        arr[index] = arr[smallerchild];
                        arr[smallerchild] = temp;

                        index = smallerchild;
                    }else{
                        break;
                    }
                }else{
                    break;
                }

            }
            return result;

        }
        return -444;
    }

    public void display(){
        if(isempty()){
            return;
        }
        System.out.print("\n[");
        for(int i=0;i<=pointer;i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println("]");
    }
}
