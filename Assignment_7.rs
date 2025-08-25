/* Implement a problem of minimum work to be done per day to finish given tasks within D days problem.  
Statement: Given an array task [] of size N denoting amount of work to be done for each task, the problem is to find the minimum amount of work to be done on each day so that all the tasks can be completed in at most D days. 
Note: On one day work can be done for only one task. */

use std::cmp;

struct Solution;

impl Solution {
    pub fn min_hours(tasks: Vec<i32>, h: i32) -> i32 {
        let mut low: i64 = 1;
        let mut high: i64 = *tasks.iter().max().unwrap() as i64;

        while low <= high {
            let mid = (low + high) / 2;
            let mut total_hours: i64 = 0;

            for &task in &tasks {
                total_hours += (task as i64 + mid - 1) / mid;
                if total_hours > h as i64 {
                    break;
                }
            }

            if total_hours <= h as i64 {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low as i32
    }
}

fn main() {
    let tasks = vec![30, 11, 23, 4, 20];
    let h = 6;
    let ans = Solution::min_hours(tasks, h);
    println!("Minimum hours required: {}", ans);
}
