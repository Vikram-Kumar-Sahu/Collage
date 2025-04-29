class BookTheaterSeat {
    int total_seat = 10;

    // Synchronized method to prevent overbooking by multiple threads
    synchronized void bookseat(int seats) {
        System.out.println(Thread.currentThread().getName() + " is trying to book " + seats + " seats.");
        if (total_seat >= seats) {
            System.out.println("Seats available. Booking now...");
            total_seat = total_seat - seats;
            System.out.println("Booking successful! Seats left: " + total_seat);
        } else {
            System.out.println("Sorry, not enough seats available for " + Thread.currentThread().getName());
            System.out.println("Seats left: " + total_seat);
        }
    }
}

public class MovieBookingApp extends Thread {
    static BookTheaterSeat b;
    int seats;

    public void run() {
        b.bookseat(seats);
    }

    public static void main(String args[]) {
        b = new BookTheaterSeat();

        MovieBookingApp d = new MovieBookingApp();
        d.seats = 7;
        d.setName("Thread-1");
        d.start();

        MovieBookingApp a = new MovieBookingApp();
        a.seats = 6;
        a.setName("Thread-2");
        a.start();
    }
}
