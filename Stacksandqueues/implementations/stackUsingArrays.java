import java.util.*;

public class stackUsingArrays {
    static class myStackUsingArr{
        private int top;
        private int[] stackArray;

        myStackUsingArr(){
            top = -1;
            stackArray = new int[10];
        }

        int getSize(){
            return top + 1;
        }
        
        public boolean isEmpty(){
            return top == -1;
        }

        public int peek(){
            if (isEmpty()){
                return -1;
            }
            return stackArray[top];
        }

        public int pop(){
            if (isEmpty()){
                return -1;
            }
            int topElement = stackArray[top];
            top--;
            return topElement;
        }

        public void push(int element){
            if(top == stackArray.length - 1){
                return;
            }
            top++;
            stackArray[top] = element;
        }

        @Override
        public String toString(){
            return Arrays.toString(stackArray);
        }
        
    }
    static class myStack<T>{
        private ArrayList<T> stackArray;

        myStack(){
            stackArray = new ArrayList<>();
        }

        public boolean isEmpty(){
            return stackArray.size() == 0;
        }
        
        public T peek(){
            if (isEmpty()){
                return null;
            }

            return stackArray.get(stackArray.size()-1);
        }

        public int getSize(){
            return stackArray.size();
        }

        public T pop(){
            if(isEmpty()){
                return null;
            }

            T topElement = stackArray.get(stackArray.size()-1);
            stackArray.remove(stackArray.size()-1);
            return topElement;
        }

        public void push(T element){
            stackArray.add(element);
        }

        @Override 
        public String toString(){
            return stackArray.toString();
        }
    }
    public static void main(String[] args) {
        myStack<Integer> st = new myStack<>();
        st.push(1);
        System.out.println(st.toString());
        
    }
}