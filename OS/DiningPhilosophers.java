import java.util.concurrent.Semaphore;
import java.util.concurrent.ThreadLocalRandom;


public class DiningPhilosophers {
    static Chopstick chopsticks[]=new Chopstick[5];
    static Philosopher philosophers[]=new Philosopher[5];
    static Semaphore room=new Semaphore(4);

    static class Chopstick{
        Semaphore mutex=new Semaphore(1);

        void grab(){
            try{
                mutex.acquire();
            }catch(InterruptedException e){
                System.out.println("Interrupted");
            }
        }
        void put(){
            mutex.release();
        }
    }

    static class Philosopher extends Thread{
        public int num;
        public Chopstick left;
        public Chopstick right;
        public Philosopher(int num ,Chopstick left,Chopstick right){
            this.num=num;
            this.left=left;
            this.right=right;
        }

        public void run(){
            while(true){
                try{
                    room.acquire();
                    left.grab();
                    right.grab();
                    eat();
    
                    left.put();
                    right.put();
                    room.release();
                }
                catch(InterruptedException e){
                    System.out.println("Interrupted error");
                }
            }
        }
    
        public void eat(){
            try{
                int sleepTime=ThreadLocalRandom.current().nextInt(0,1000);
                System.out.println("Philosopher"+(num+1)+"eats for"+sleepTime+" ms");
                Thread.sleep(sleepTime);
            }catch(InterruptedException e){
                e.printStackTrace(System.out);
            }
        }
    }
        public static void main(String[] args) {
            for(int i=0;i<5;i++){
                chopsticks[i]=new Chopstick();
            }
            for(int i=0;i<5;i++){
                philosophers[i]=new Philosopher(i, chopsticks[i], chopsticks[(i+1)%5]);
                philosophers[i].start();
            }
        }
}


