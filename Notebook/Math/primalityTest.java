import java.io.*;
import java.math.*;
import java.util.*;

class Main {
  static public void main(String[] args) {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    Scanner scanner = new Scanner(br);
    PrintWriter printer = new PrintWriter(bw);

    BigInteger p = scanner.nextBigInteger();

    if (p.isProbablePrime(10))
      printer.printf("The number is prime\n");
    else
      printer.printf("The number is composite\n");

    printer.close();
  }
}
