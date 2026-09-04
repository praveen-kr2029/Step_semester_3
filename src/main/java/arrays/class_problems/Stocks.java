package main.c++.class_problems;

public public class Stocks {

    public static int maxProfit(int[] prices) {

                /*| Day | Index(i) | Price |
                  |   1 |     0    |     7 |
                  |   2 |     1    |     1 |
                  |   3 |     2    |     5 |
                  |   4 |     3    |     3 |
                  |   5 |     4    |     6 |
                  |   6 |     5    |     4 |
                 */
                                              //         0  1  2  3  4  5 -> INDEX(i)
                                             //prices = {7, 1, 5, 3, 6, 4}   prices.length=6

        int minPrice = prices[0];  //minPrice = 7
        int maxProfit = 0;
                                                      //ITERATION1            //ITERATION 2                //ITERATION 3              //ITERATION 4            //ITERATION 5
        for (int i = 1; i < prices.length; i++) {    //i=1, 1<6               ||i=2, 2<6                   ||i=3, 3<6                ||i=4, 4<6                //i=5, 5<6

            if (prices[i] < minPrice) {             //1<7 -> true             ||prices[2] -> 5<1->false    ||prices[3] ->3<1->false  ||prices[4] -> 6<1->false //4<1->false
                minPrice = prices[i];              //minPrice = 1             ||                           ||                        ||                        ||
            }

            int profit = prices[i] - minPrice;     //profit = 1-1 =0          ||profit = 5-1 = 4           ||profit = 3-1 =2          ||profit =6-1            //profit=4-1

            if (profit > maxProfit) {              //0>0 -> false             ||4>0->true                  ||2>4->false                ||5>4->true             //3>5->false
                maxProfit = profit;               //                          ||maxprofit = 4              ||                          ||maxProfit=5           //
            }
        }

        return maxProfit;
    }

    public static void main(String[] args) {

        int[] prices = {7, 1, 5, 3, 6, 4};

        int result = maxProfit(prices);

        System.out.println("Maxmimum profit earnable : "+ result);
    }
}

 {
    
}
