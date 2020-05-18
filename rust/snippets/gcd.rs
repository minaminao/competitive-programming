fn gcd(x: usize, y: usize) -> usize {
    if y > 0 {
        gcd(y, x % y)
    } else {
        x
    }
}
