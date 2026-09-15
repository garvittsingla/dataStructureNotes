import javax.sound.sampled.SourceDataLine;

public class QueueUsingLinkedList {

    static class Node{
        public int val;
        public Node next;
        
        public Node(int val){
            this.val = val;
            this.next = null;
        }
        public Node(int val,Node next){
            this.val = val;
            this.next = next;
        }
        
    }

    static class myQueue {
        private Node front;
        private Node rear;
        private int size;

        myQueue(){
            this.size = 0;
            this.front = null;
            this.rear = null;
        }

        public boolean isEmpty(){
            return front == null;
        }
        
        public void enqueue(int element){
            Node newNode = new Node(element);

            if(isEmpty()){
                front = newNode;
                rear = newNode;
            }else{
               rear.next = newNode;
               rear = newNode;
            }
            size++;
        }

        public int dequeue(){
            if(isEmpty()){
                return -1;
            }
            size--;
            int val = front.val;
            front = front.next;
            if(size == 0){
                front = null;
                rear = null;
            }
            return val;
        }
    }
    public static void main(String[] args) {
        myQueue q = new myQueue();
        q.enqueue(1);
        q.enqueue(2);
        System.out.println(q.size);
        q.dequeue();
        System.out.println(q.size);
        q.dequeue();
        System.out.println(q.size);
        q.enqueue(23);
        System.out.println(q.size);
        System.out.println(q.dequeue());
        
        
    }
    
}