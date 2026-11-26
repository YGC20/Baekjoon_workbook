use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Input fail");
    let n:i32 = input.trim().parse().expect("Not Numbers");

    let mut count = 0;
    let mut ten = n / 10;
    let mut one = n % 10;
    loop {
        let temp = one;
        one = (ten + one) % 10;
        ten = temp;
        count += 1;
        if ten == n / 10 && one == n % 10 { break; }
    }
    println!("{}",count);
}