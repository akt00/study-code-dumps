package org.example;
import java.util.function.*;
import java.util.stream.*;
public class Main {
    public enum Color {
        RED("RED"),
        GREEN("GREEN"),
        BLUE("BLUE");
        Color(String arg) {}
    }
    public static void higher_order(IntFunction<Float> arg) {

        var ret = arg.apply(11);
        System.out.println("value = " + ret);
    }
    public static void main(String[] args) {
        Stream<Integer> stream = Stream.of(1,2,3,4,5,6,7,8,9);
        stream.forEach(p -> System.out.println(p));
        BiFunction<Integer, Integer, Integer> addFunction = (a, b) -> a + b;


    }
}

/*
1. pass by reference
2. shallow copy
3. stream API
4. process API
5. hidden class
6. sealed class
 */
