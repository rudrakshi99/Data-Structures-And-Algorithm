package example;

public class Main {

    public static int x=0; //shared data which leads to race condition

    public static void main(String[] args) throws InterruptedException {
        Object obj = new Object();
        Thread t1 = new Thread(new MyRunnable(obj));
        Thread t2 = new Thread(new MyRunnable(obj));
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        System.out.println(x);
    }
}
