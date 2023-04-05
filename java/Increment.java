package org.example;
import java.util.Iterator;

public class Increment implements Iterable<Integer> {
    private int counter;
    public Increment() {
        this.counter = 0;
    }

    @Override
    public Iterator<Integer> iterator() {
        // anonymous class
        return new Iterator<>() {
            @Override
            public boolean hasNext() {
                return Increment.this.counter < 100;
            }
            @Override
            public Integer next() {
                return Increment.this.counter++;
            }
            @Override
            public void remove() {
                throw new UnsupportedOperationException();
            }
        };
    }
}
