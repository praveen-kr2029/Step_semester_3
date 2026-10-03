import java.util.Scanner;

abstract class Staff {
    String name;

    public Staff(String name) {
        this.name = name;
    }

    public abstract double calculatePay();

    public void printPay() {
        System.out.printf("%s: %.2f%n", name, calculatePay());
    }
}

class FullTimeStaff extends Staff {
    double weeklySalary;
    public FullTimeStaff(String name, double weeklySalary) {
        super(name);
        this.weeklySalary = weeklySalary;
    }
    @Override
    public double calculatePay() {
        return weeklySalary;
    }
}

class HourlyStaff extends Staff {
    double hours, rate;
    public HourlyStaff(String name, double hours, double rate) {
        super(name);
        this.hours = hours;
        this.rate = rate;
    }
    @Override
    public double calculatePay() {
        if (hours <= 40) {
            return hours * rate;
        } else {
            return (40 * rate) + ((hours - 40) * 1.5 * rate);
        }
    }
}

class InternStaff extends Staff {
    double stipend;
    public InternStaff(String name, double stipend) {
        super(name);
        this.stipend = stipend;
    }
    @Override
    public double calculatePay() {
        return stipend;
    }
}

public class WeeklyStaffPay {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        Staff[] staffList = new Staff[n];
        double totalPayroll = 0;

        for (int i = 0; i < n; i++) {
            String type = scanner.next();
            String name = scanner.next();
            if (type.equals("FULLTIME")) {
                staffList[i] = new FullTimeStaff(name, scanner.nextDouble());
            } else if (type.equals("HOURLY")) {
                staffList[i] = new HourlyStaff(name, scanner.nextDouble(), scanner.nextDouble());
            } else if (type.equals("INTERN")) {
                staffList[i] = new InternStaff(name, scanner.nextDouble());
            }
            totalPayroll += staffList[i].calculatePay();
        }
        scanner.close();

        for (Staff staff : staffList) {
            staff.printPay();
        }
        System.out.printf("Total Payroll: %.2f%n", totalPayroll);
    }
}