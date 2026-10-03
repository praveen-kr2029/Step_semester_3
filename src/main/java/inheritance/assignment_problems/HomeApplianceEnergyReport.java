import java.util.Scanner;

interface SaverModeSupport {}

abstract class Appliance {
    String name;
    double hours;
    boolean saverRequested;

    public Appliance(String name, double hours, boolean saverRequested) {
        this.name = name;
        this.hours = hours;
        this.saverRequested = saverRequested;
    }

    public abstract double getPowerWatts();

    public void processReport() {
        if (saverRequested && !(this instanceof SaverModeSupport)) {
            System.out.println(name + ": saver mode not supported");
            return;
        }

        double units = (getPowerWatts() * hours) / 1000.0;
        if (saverRequested) {
            units -= 0.25 * units;
        }
        double cost = units * 8.0;
        System.out.printf("%s: Units=%.2f Cost=%.2f%n", name, units, cost);
    }

    public double getCost() {
        if (saverRequested && !(this instanceof SaverModeSupport)) {
            return 0.0;
        }
        double units = (getPowerWatts() * hours) / 1000.0;
        if (saverRequested) {
            units -= 0.25 * units;
        }
        return units * 8.0;
    }
}

class Fridge extends Appliance {
    public Fridge(double hours, boolean saver) { super("FRIDGE", hours, saver); }
    @Override public double getPowerWatts() { return 150.0; }
}

class AirConditioner extends Appliance implements SaverModeSupport {
    public AirConditioner(double hours, boolean saver) { super("AC", hours, saver); }
    @Override public double getPowerWatts() { return 1500.0; }
}

class TV extends Appliance {
    public TV(double hours, boolean saver) { super("TV", hours, saver); }
    @Override public double getPowerWatts() { return 100.0; }
}

class WashingMachine extends Appliance implements SaverModeSupport {
    public WashingMachine(double hours, boolean saver) { super("WASHER", hours, saver); }
    @Override public double getPowerWatts() { return 500.0; }
}

public class HomeApplianceEnergyReport {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        Appliance[] apps = new Appliance[n];
        double totalCost = 0;

        for (int i = 0; i < n; i++) {
            String type = scanner.next();
            double hours = scanner.nextDouble();
            boolean saver = false;
            if (scanner.hasNext()) {
                String token = scanner.next();
                if (token.equals("SAVER")) {
                    saver = true;
                } else {
                    // if it wasn't SAVER, handle it if needed or push back logic (in simple inputs, it's either hours or hours SAVER)
                }
            }

            if (type.equals("FRIDGE")) {
                apps[i] = new Fridge(hours, saver);
            } else if (type.equals("AC")) {
                apps[i] = new AirConditioner(hours, saver);
            } else if (type.equals("TV")) {
                apps[i] = new TV(hours, saver);
            } else if (type.equals("WASHER")) {
                apps[i] = new WashingMachine(hours, saver);
            }
            totalCost += apps[i].getCost();
        }
        scanner.close();

        for (Appliance app : apps) {
            app.processReport();
        }
        System.out.printf("Total Cost: %.2f%n", totalCost);
    }
}