// Recursive Digit Sum - hackerrank
/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
  
 *  2. INTEGER k
 */
int superDigitHelper(int num){
    if (num < 10){
        return num;
    }
    int sum = 0;
    while (num > 0){
        sum += num % 10;
        num /= 10;
    }
    return superDigitHelper(sum);
}
int superDigit(string n, int k) {
    int sum = 0;
    for (char c : n){
        sum += c - '0';
    }
    sum *= k;
    return superDigitHelper(sum);
}
