public class stackUsingLinkedList {
    static class Node{
        public int val;
        public Node next;
        Node(int val,Node next){
            this.next = next;
            this.val = val;
        }
        
    }
    static class myStack{
        private int size;
        private Node head;
        myStack(){
            head = null;
            size = 0;
        }

        public int getSize(){
            return size;
        }

        public boolean isEmpty(){
            return size == 0;
        }

        public void push(int item){
            Node newNode = new Node(item, head);
            head = newNode;
            size++;
        }

        public int pop(){
            if(isEmpty()){
                return -1;
            }
            int val = head.val;
            head = head.next;
            size--;
            return val;
        }

        public int peek(){
            if(isEmpty()){
                return -1;
            }
            return head.val;
        }
    }
    public static void main(String[] args) {
        myStack stack = new myStack();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.println(stack.peek());
        System.out.println(stack.pop());
        System.out.println(stack.peek());
        System.out.println(stack.isEmpty());
        System.out.println(stack.getSize());
    }
}