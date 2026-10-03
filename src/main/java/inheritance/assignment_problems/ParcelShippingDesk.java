import java.util.Scanner;

interface Insurable {
    double calculateInsurance();
}

abstract class Parcel {
    double weight;
    double declaredValue;
    String typeName;

    public Parcel(String typeName, double weight, double declaredValue) {
        this.typeName = typeName;
        this.weight = weight;
        this.declaredValue = declaredValue;
    }

    public abstract double calculateCharge();

    public double calculateInsurance() {
        return 0.0;
    }

    public void printReport() {
        double charge = calculateCharge();
        double insurance = calculateInsurance();
        double total = charge + insurance;
        System.out.printf("%s: Charge=%.2f Insurance=%.2f Total=%.2f%n", typeName, charge, insurance, total);
    }
}

class StandardParcel extends Parcel {
    public StandardParcel(double weight, double declaredValue) {
        super("STANDARD", weight, declaredValue);
    }
    @Override
    public double calculateCharge() {
        return 40.0 + (10.0 * weight);
    }
}

class ExpressParcel extends Parcel implements Insurable {
    public ExpressParcel(double weight, double declaredValue) {
        super("EXPRESS", weight, declaredValue);
    }
    @Override
    public double calculateCharge() {
        return 80.0 + (15.0 * weight);
    }
    @Override
    public double calculateInsurance() {
        return 0.02 * declaredValue;
    }
}

class FragileParcel extends Parcel implements Insurable {
    public FragileParcel(double weight, double declaredValue) {
        super("FRAGILE", weight, declaredValue);
    }
    @Override
    public double calculateCharge() {
        // Standard charge plus handling fee of 50
        return (40.0 + (10.0 * weight)) + 50.0;
    }
    @Override
    public double calculateInsurance() {
        return 0.02 * declaredValue;
    }
}

public class ParcelShippingDesk {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        Parcel[] parcels = new Parcel[n];
        double grandTotal = 0;

        for (int i = 0; i < n; i++) {
            String type = scanner.next();
            double weight = scanner.nextDouble();
            double value = scanner.nextDouble();
            if (type.equals("STANDARD")) {
                parcels[i] = new StandardParcel(weight, value);
            } else if (type.equals("EXPRESS")) {
                parcels[i] = new ExpressParcel(weight, value);
            } else if (type.equals("FRAGILE")) {
                parcels[i] = new FragileParcel(weight, value);
            }
            grandTotal += parcels[i].calculateCharge() + parcels[i].calculateInsurance();
        }
        scanner.close();

        for (Parcel p : parcels) {
            p.printReport();
        }
        System.out.printf("Grand Total: %.2f%n", grandTotal);
    }
}