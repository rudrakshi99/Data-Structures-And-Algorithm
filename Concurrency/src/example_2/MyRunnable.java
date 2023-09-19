package example_2;

import java.util.List;

class MyRunnable implements Runnable {
    private final int v;
    private final List<Integer> sharedList;

    public MyRunnable(int v, List<Integer> sharedList) {
        this.v = v;
        this.sharedList = sharedList;
    }

    @Override
    public void run() {
        sharedList.add(v);
    }
}
