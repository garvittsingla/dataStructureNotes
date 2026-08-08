import java.util.ArrayList;

public class Implemantation {

    static class Heap<T extends Comparable<T>> {

        private ArrayList<T> list;

        public Heap() {
            list = new ArrayList<>();
        }

        private void swap(int first, int second) {
            T temp = list.get(first);
            list.set(first, list.get(second));
            list.set(second, temp);
        }

        private int parent(int index) {
            return (index - 1) / 2;
        }

        private int left(int index) {
            return 2 * index + 1;
        }

        private int right(int index) {
            return 2 * index + 2;
        }

        public void insert(T value) {
            list.add(value);
            upheap(list.size() - 1);
        }

        private void upheap(int index) {
            if (index == 0)
                return;

            int p = parent(index);

            if (list.get(index).compareTo(list.get(p)) < 0) {
                swap(index, p);
                upheap(p);
            }
        }

        public T remove() {
            if (list.isEmpty()) {
                return null;
            }

            T temp = list.get(0);
            T last = list.remove(list.size() - 1);

            if (!list.isEmpty()) {
                list.set(0, last);
                downheap(0);
            }

            return temp;
        }

        private void downheap(int index) {
            int min = index;

            int left = left(index);
            int right = right(index);

            if (left < list.size() &&
                list.get(left).compareTo(list.get(min)) < 0) {
                min = left;
            }

            if (right < list.size() &&
                list.get(right).compareTo(list.get(min)) < 0) {
                min = right;
            }

            if (min != index) {
                swap(index, min);
                downheap(min);
            }
        }

        public T peek() {
            if (list.isEmpty()) {
                return null;
            }
            return list.get(0);
        }

        public boolean isEmpty() {
            return list.isEmpty();
        }

        public int size() {
            return list.size();
        }

        public void display() {
            System.out.println(list);
        }
    }

    public static void main(String[] args) {

        Heap<Integer> heap = new Heap<>();

        heap.insert(10);
        heap.insert(4);
        heap.insert(15);
        heap.insert(2);
        heap.insert(8);
        heap.insert(1);

        heap.display();

        while (!heap.isEmpty()) {
            System.out.print(heap.remove() + " ");
        }
    }
}