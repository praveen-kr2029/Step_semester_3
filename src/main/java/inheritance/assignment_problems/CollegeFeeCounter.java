import java.util.Scanner;

interface BusUser {
    double getTransportFee();
}

abstract class Student {
    String name;
    String typeName;

    public Student(String typeName, String name) {
        this.typeName = typeName;
        this.name = name;
    }

    public abstract double calculateTuition();

    public double calculateTotalFee() {
        double fee = calculateTuition();
        if (this instanceof BusUser) {
            fee += ((BusUser) this).getTransportFee();
        }
        return fee;
    }

    public void printReport() {
        System.out.printf("%s: %.2f%n", name, calculateTotalFee());
    }
}

class DayScholar extends Student implements BusUser {
    public DayScholar(String name) { super("DAY_SCHOLAR", name); }
    @Override public double calculateTuition() { return 40000.0; }
    @Override public double getTransportFee() { return 12000.0; }
}

class Hosteller extends Student {
    public Hosteller(String name) { super("HOSTELLER", name); }
    @Override public double calculateTuition() { return 40000.0 + 60000.0; }
}

class ScholarStudent extends Student implements BusUser {
    public ScholarStudent(String name) { super("SCHOLAR", name); }
    @Override public double calculateTuition() { return 20000.0; }
    @Override public double getTransportFee() { return 12000.0; }
}

public class CollegeFeeCounter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        Student[] students = new Student[n];
        double totalCollected = 0;

        for (int i = 0; i < n; i++) {
            String type = scanner.next();
            String name = scanner.next();
            if (type.equals("DAY_SCHOLAR")) {
                students[i] = new DayScholar(name);
            } else if (type.equals("HOSTELLER")) {
                students[i] = new Hosteller(name);
            } else if (type.equals("SCHOLAR")) {
                students[i] = new ScholarStudent(name);
            }
            totalCollected += students[i].calculateTotalFee();
        }
        scanner.close();

        for (Student s : students) {
            s.printReport();
        }
        System.out.printf("Total Collected: %.2f%n", totalCollected);
    }
}