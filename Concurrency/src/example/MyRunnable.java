package example;

public class MyRunnable implements Runnable {

    private final Object obj;

    public MyRunnable(Object obj){
        this.obj = obj;
    }

    @Override
    public void run() {
        for(int i=0;i<100000; i++)
        //acquire lock
        {
            synchronized (obj) {
                Main.x++; //critical section
            }

        }
        //release lock
    }

    //var = var + 1
    //Not a 1-step
    //Fetch, update, write
}
