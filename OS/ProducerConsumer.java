import java.util.Scanner;
import java.util.concurrent.Semaphore;

//release ->signal
//acquire ->wait


public class ProducerConsumer {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Buffer b=new Buffer(5);

        while(true){
            System.out.println("Enter 1 to produce,2 to consume or 3 to exit");

            int choice=sc.nextInt();

            if(choice==1){
                System.out.println("Enter Item no: ");
                int n=sc.nextInt();
                new Producer(b, n).run();
            }
            else if(choice==2){
                new Consumer(b).run();
            }else if(choice==3){
                System.out.println("Exiting...");
                break;
            }
            else{
                System.out.println("Invalid choice");
            }
        }
    }
    
}

class Buffer{
    Semaphore empty;
    Semaphore full;
    Semaphore S;  //mutex
    int in,out,size;
    int buffer[];

    Buffer(int size){
        this.size=size;
        in=0;
        out=0;
        empty=new Semaphore(size);
        full =new Semaphore(0);
        S=new Semaphore(1);
        buffer=new int[size];
    }

    void put(int item){
        try{
            if (empty.availablePermits() == 0) {
                System.out.println("Cannot produce. Buffer is full.");
                return;
            }
            empty.acquire();
        }catch(InterruptedException e){
            System.out.println("Interrupted!");
        }

        try{
            S.acquire();
        }catch(InterruptedException e){
            System.out.println("Interrupted!");
        }
        buffer[in]=item;
        System.out.println("Produced produced item "+item);
        in=(in+1)%size;
        printBuffer();
        S.release();
        full.release();
    }

    void get(){
        try{
            if (full.availablePermits() == 0) {
                System.out.println("Cannot consume. Buffer is empty.");
                return;
            }

            full.acquire();
        }catch(InterruptedException e){
            System.out.println("Interrupted!");
        }

        try{
            S.acquire();
        }catch(InterruptedException e){
            System.out.println("Interrupted!");
        }
        System.out.println("Produced produced item "+buffer[out]);
        buffer[out]=0;
        out=(out+1)%size;
        printBuffer();
        S.release();
        empty.release();
    }

    void printBuffer(){
        System.out.println("Buffer: ");
        for(int i=0;i<size;i++){
            System.out.print(buffer[i]+" ");
        }
        System.out.println();
    }

}


class Producer implements Runnable{
    int itemNo;
    Buffer b;
    Producer(Buffer b,int itemNo){
        this.b=b;
        this.itemNo=itemNo;
    }
    public void run(){
        b.put(itemNo);
    }
}

class Consumer implements Runnable{
    Buffer b;
    Consumer(Buffer b){
        this.b=b;
    }

    public void run(){
        b.get();
    }
}