package example_2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        List<Integer> sharedList = Collections.synchronizedList(new ArrayList<>());

        // Create threads and add values to the shared list
        Thread t1 = new Thread(new MyRunnable(1, sharedList));
        Thread t2 = new Thread(new MyRunnable(2, sharedList));
        Thread t3 = new Thread(new MyRunnable(3, sharedList));
        Thread t4 = new Thread(new MyRunnable(4, sharedList));
        Thread t5 = new Thread(new MyRunnable(5, sharedList));

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();

        // Wait for all threads to finish
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();

        // Sort the shared list
        Collections.sort(sharedList);

        // Print the sorted numbers
        for (Integer num : sharedList) {
            System.out.println(num);
        }
    }


}
