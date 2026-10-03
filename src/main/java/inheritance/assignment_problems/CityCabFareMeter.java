// package main.c++.inheritance.assignment_problems;

public import java.util.Scanner;

interface NightServiceable {}

abstract class Cab {
    String cabType;
    double km;
    String time;

    public Cab(String cabType, double km, String time) {
        this.cabType = cabType;
        this.km = km;
        this.time = time;
    }

    public abstract double getRatePerKm();

    public double calculateFare() {
        if (time.equals("NIGHT") && !(this instanceof NightServiceable)) {
            return -1; // indicates rejection
        }
        double fare = km * getRatePerKm();
        if (fare < 100.0) {
            fare = 100.0;
        }
        if (time.equals("NIGHT")) {
            fare += 0.20 * fare;
        }
        return fare;
    }
}

class MiniCab extends Cab {
    public MiniCab(double km, String time) { super("MINI", km, time); }
    @Override public double getRatePerKm() { return 10.0; }
}

class SedanCab extends Cab implements NightServiceable {
    public SedanCab(double km, String time) { super("SEDAN", km, time); }
    @Override public double getRatePerKm() { return 14.0; }
}

class SuvCab extends Cab implements NightServiceable {
    public SuvCab(double km, String time) { super("SUV", km, time); }
    @Override public double getRatePerKm() { return 18.0; }
}

public class CityCabFareMeter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        double total = 0;

        // Store trips output or print directly
        for (int i = 0; i < n; i++) {
            String type = scanner.next();
            double km = scanner.nextDouble();
            String time = scanner.next();

            Cab cab = null;
            if (type.equals("MINI")) cab = new MiniCab(km, time);
            else if (type.equals("SEDAN")) cab = new SedanCab(km, time);
            else if (type.equals("SUV")) cab = new SuvCab(km, time);

            double fare = cab.calculateFare();
            if (fare == -1) {
                System.out.println(type + ": night service not available");
            } else {
                System.out.printf("%s: %.2f%n", type, fare);
                total += fare;
            }
        }
        scanner.close();
        System.out.printf("Total: %.2f%n", total);
    }
} {
    
}
