class Bus extends Thread{
    int tickets;
    Bus(int tickets){
        this.tickets=tickets;
    }

   public synchronized void bookTickets(){
        if(tickets>0){
            try{
                Thread.sleep(1500);
                tickets--;
                System.out.println("Ticket Booked by :"+Thread.currentThread().getName());

            }
            catch(Exception e){

            }
        }
        else{
            System.out.println("House Full!");
        }

    }

    public void run(){
        bookTickets();
    }
}

public class MultithreadingSync{
    public static void main(String[] args) {
        System.out.println("Asynchronous");
        Bus b1=new Bus(1);
        b1.run();
        b1.run();
        System.out.println("Synchronous");
        Bus b2=new Bus(1);
        Thread t1=new Thread(b2);
        t1.setName("Arnav");
        Thread t2=new Thread(b2);
        t2.setName("Sanjana");
        t1.start();
        t2.start();

    }
}