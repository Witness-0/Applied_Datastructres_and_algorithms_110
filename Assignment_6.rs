/*
Implement a problem of maximizing Profit by trading stocks based on given rate per day.  
Statement: Given an array arr[] of N positive integers which denotes the cost of selling and buying stock on each of the N days. The task is to find the maximum profit that can be earned by buying a stock on or selling all previously bought stocks on a particular day.
*/


struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let n = prices.len();
        if n <= 1 {
            return 0;
        }

        let mut profit = 0;
        let mut buy = prices[0];
        let mut holding = false;

        for i in 1..n {
            if !holding && prices[i] > prices[i - 1] {
                buy = prices[i - 1];
                holding = true;
            }

            if holding && prices[i] < prices[i - 1] {
                profit += prices[i - 1] - buy;
                holding = false;
            }
        }

        if holding {
            profit += prices[n - 1] - buy;
        }

        profit
    }
}

fn main() {
    let arr = vec![100, 180, 260, 310, 40, 535, 695];
    println!("Maximum Profit: {}", Solution::max_profit(arr));
}
