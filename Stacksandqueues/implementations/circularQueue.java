public class circularQueue {
    static class myQueue{
        private int[] queueArray;
        private int front;
        private int rear;
        private int capacity;
        private int size;

        public myQueue(int capacity) {
            this.queueArray = new int[capacity];
            this.front = -1;
            this.rear = -1;
            this.capacity = capacity;
            this.size = 0;
        }

        public boolean isEmpty(){
            return size == 0;
        }

        public boolean isFull(){
            return size == capacity;
        }
        
        public void enqueue(int element){
            if(isFull()) return;
            if(isEmpty()){
                front = 0;
                rear = 0;
                queueArray[rear] = element;
                size++;
                return;
            }else{
                rear = (rear + 1) % capacity;
                queueArray[rear] = element;
                size++;
            }
            
        }

        public int dequeue(){
            if(isEmpty()) return -1;
            int element = queueArray[front];
            front = (front + 1) % capacity;
            size--;
            return element;
        }

        
    }
    public static void main(String[] args) {
        myQueue q = new myQueue(4);
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
        q.enqueue(23);
        System.out.println(q.size);
        System.out.println(q.dequeue());
    }
}