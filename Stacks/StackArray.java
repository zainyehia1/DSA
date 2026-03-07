public class StackArray <T> {
    private int size;
    private int top;
    private T s[];
    
    // Default constructor
    public StackArray(){
        this.size = 10;
        this.top = -1;
        this.s = (T[]) new Object[10];
    }
    
    // Parameterized Constructor
    public StackArray(int size){
        if(size < 1)
            throw new IllegalArgumentException("Minimum stack size is 1!");
        this.size = size;
        this.top = -1;
        this.s = (T[]) new Object[size];
    }

    public boolean isFull(){
        return this.top == this.size - 1; 
    }
    
    public boolean isEmpty(){
        return this.top == -1;
    }

    public boolean push(T val){
        if(this.isFull()){
            System.out.println("Stack overflow!");
            return false;
        }
        
        this.top++;
        this.s[this.top] = val;
        return true;
    }
    
    public T pop(){
        if(isEmpty()){
            System.out.println("Stack is empty! Nothing to pop!");
            return null;
        }
        
        return this.s[this.top--];
    }
    
    public T peek(int position){
        if(isEmpty()){
            System.out.println("Stack is empty! Nothing to peek!");
            return null;
        }
        
        int index = this.top - position + 1;
        
        if(index < 0 || index > this.top){
            System.out.println("Invalid position!");
            return null;
        }
        
        return this.s[index];
    }
    
    public T stackTop(){
        if(isEmpty()){
            System.out.println("Stack is empty!");
            return null;
        }
        
        return this.s[this.top];
    }
    
    public int size(){
        return this.top + 1;
    }
}