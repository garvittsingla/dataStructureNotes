public class QueueUsingArrays {

    static class myQueue{
        private int[] queueArray;
        private int front;
        private int rear;
        private int capacity;

        myQueue(int capacity){
            this.queueArray = new int[capacity];
            this.capacity = capacity;
            this.front = -1;
            this.rear = -1;
        }
        public boolean isEmpty(){
            return front == -1;
        }
        
        public void enqueue(int element){
            if(rear == capacity - 1){
                return;
            }

            rear++;
            queueArray[rear] = element;
            
            if(front == -1){
                front = 0;
            }
        }

        public int dequeue(){
            int element = peek();
            rear--;
            if(rear == -1) front = -1;
            return element;
        }

        public int peek(){
            if(isEmpty()) return -1;
            return queueArray[front];
        }

    }
    public static void main(String[] args) {
        
    }

    
}