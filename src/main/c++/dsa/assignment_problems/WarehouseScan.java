public public class WarehouseScan {

    public static class SummaryResult {
        long totalItems;
        int[] maxCoordinate;

        public SummaryResult(long totalItems, int[] maxCoordinate) {
            this.totalItems = totalItems;
            this.maxCoordinate = maxCoordinate;
        }
    }

    public static SummaryResult warehouseSummary(int[][] grid) {
        long total = 0;
        int maxVal = -1;
        int[] maxCoord = {-1, -1};

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                total += grid[i][j];
                if (grid[i][j] > maxVal) {
                    maxVal = grid[i][j];
                    maxCoord = new int[]{i, j};
                }
            }
        }
        return new SummaryResult(total, maxCoord);
    }

    public static void main(String[] args) {
        int[][] grid = {
            {4, 9, 2},
            {7, 1, 6},
            {3, 12, 5}
        };

        SummaryResult res = warehouseSummary(grid);
        System.out.println("total = " + res.totalItems + ", maxCoordinate = (" + res.maxCoordinate[0] + ", " + res.maxCoordinate[1] + ")");
    }
} {
    
}
