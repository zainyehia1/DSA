public class StackLL <T>{
    
    private class Node {
        private T data;
        private Node next;
        
        public Node(T data, Node next){
            this.data = data;
            this.next = next;
        }
        
        
    }
    
    private Node top;
    
    public StackLL(){
        this.top = null;
    }
    
    public boolean isEmpty(){
        return this.top == null;
    }
    
    public boolean push(T val){
        this.top = new Node(val, top);
        return true;
    }
    
    public T pop(){
        if(this.isEmpty()){
            System.out.println("Stack is empty! Nothing to Pop");
            return null;
        }
        
        T popped = this.top.data;
        
        top = top.next;
        
        return popped;
    }
    
    public T peek(int position){
        
        if(this.isEmpty()){
            System.out.println("Stack is empty! Nothing to Peek");
            return null;
        }
        
        if(position < 0)
            throw new IllegalArgumentException("Invalid index!");
        
        Node t = top;
        for(int i = 0; t != null && i < position; i++){
            t = t.next;
        }
        
        if(t == null)
            throw new IllegalArgumentException("Position out of bounds!");
        
        return t.data;
    }
    
    public T stackTop(){
        if(isEmpty()){
            System.out.println("Stack is empty!");
            return null;
        }
        
        return this.top.data;
    }
    
    public int size(){
        int size = 0;
        
        Node t = top;
        while(t != null){
            size++;
            t = t.next;
        }
        
        return size;
    }
    
}