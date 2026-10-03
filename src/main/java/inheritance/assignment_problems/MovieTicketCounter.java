import java.util.Scanner;

abstract class Ticket {
    String seatType;
    int count;
    
    public Ticket(String seatType, int count) {
        this.seatType = seatType;
        this.count = count;
    }
    
    public abstract double getPricePerTicket();
    
    public double calculateAmount() {
        // Convenience fee of 20 per ticket is written here in one place
        return (getPricePerTicket() + 20.0) * count;
    }
    
    public void printBooking() {
        System.out.printf("%s: %.2f%n", seatType, calculateAmount());
    }
}

class RegularTicket extends Ticket {
    public RegularTicket(int count) { super("REGULAR", count); }
    @Override public double getPricePerTicket() { return 150.0; }
}

class PremiumTicket extends Ticket {
    public PremiumTicket(int count) { super("PREMIUM", count); }
    @Override public double getPricePerTicket() { return 250.0; }
}

class ReclinerTicket extends Ticket {
    public ReclinerTicket(int count) { super("RECLINER", count); }
    @Override public double getPricePerTicket() { return 400.0; }
}

public class MovieTicketCounter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        Ticket[] tickets = new Ticket[n];
        double total = 0;

        for (int i = 0; i < n; i++) {
            String seat = scanner.next();
            int count = scanner.nextInt();
            if (seat.equals("REGULAR")) {
                tickets[i] = new RegularTicket(count);
            } else if (seat.equals("PREMIUM")) {
                tickets[i] = new PremiumTicket(count);
            } else if (seat.equals("RECLINER")) {
                tickets[i] = new ReclinerTicket(count);
            }
            total += tickets[i].calculateAmount();
        }
        scanner.close();

        for (Ticket t : tickets) {
            t.printBooking();
        }
        System.out.printf("Total: %.2f%n", total);
    }
}