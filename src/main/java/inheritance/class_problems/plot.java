import java.util.Scanner;

abstract class Plot {
    String owner;
    String shapeName;

    public Plot(String owner, String shapeName) {
        this.owner = owner;
        this.shapeName = shapeName;
    }

    public abstract double calculateArea();

    public void printReport() {
        System.out.printf("%s (%s): %.2f%n", owner, shapeName, calculateArea());
    }
}

class CirclePlot extends Plot {
    double radius;
    public CirclePlot(String owner, double radius) {
        super(owner, "CIRCLE");
        this.radius = radius;
    }
    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }
}

class RectanglePlot extends Plot {
    double length, width;
    public RectanglePlot(String owner, double length, double width) {
        super(owner, "RECTANGLE");
        this.length = length;
        this.width = width;
    }
    @Override
    public double calculateArea() {
        return length * width;
    }
}

class TrianglePlot extends Plot {
    double base, height;
    public TrianglePlot(String owner, double base, double height) {
        super(owner, "TRIANGLE");
        this.base = base;
        this.height = height;
    }
    @Override
    public double calculateArea() {
        return 0.5 * base * height;
    }
}

public class GardenPlotReport {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        Plot[] plots = new Plot[n];
        double totalArea = 0;

        for (int i = 0; i < n; i++) {
            String shape = scanner.next();
            String owner = scanner.next();
            if (shape.equals("CIRCLE")) {
                plots[i] = new CirclePlot(owner, scanner.nextDouble());
            } else if (shape.equals("RECTANGLE")) {
                plots[i] = new RectanglePlot(owner, scanner.nextDouble(), scanner.nextDouble());
            } else if (shape.equals("TRIANGLE")) {
                plots[i] = new TrianglePlot(owner, scanner.nextDouble(), scanner.nextDouble());
            }
            totalArea += plots[i].calculateArea();
        }
        scanner.close();

        for (Plot plot : plots) {
            plot.printReport();
        }
        System.out.printf("Total Area: %.2f%n", totalArea);
    }
}