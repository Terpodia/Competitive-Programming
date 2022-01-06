import java.io.*;
import java.math.*;
import java.util.*;
import java.security.SecureRandom;

class Main {
  private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

  private static Scanner sc = new Scanner(br);
  private static PrintWriter pw = new PrintWriter(bw);

  private static BigInteger TWO = BigInteger.valueOf(2);

  private final static SecureRandom random = new SecureRandom();

  private static TreeMap<BigInteger, Integer> factors = new TreeMap<BigInteger, Integer>();

  private static BigInteger f(BigInteger x, BigInteger n, BigInteger b) {
    return x.multiply(x).mod(n).add(b).mod(n);
  }

  private static BigInteger rho(BigInteger n) {
    if (n.mod(TWO).compareTo(BigInteger.ZERO) == 0) return TWO;
    BigInteger b = new BigInteger(n.bitLength(), random);
    BigInteger x = new BigInteger(n.bitLength(), random);
    BigInteger y = x;

    while (true) {
      x = f(x, n, b);
      y = f(f(y, n, b), n, b);
      BigInteger d = x.subtract(y).gcd(n);

      if (d.compareTo(BigInteger.ONE) != 0)
        return d;
    }
  }

  public static void pollard_rho(BigInteger n) {
    if (n.compareTo(BigInteger.ONE) <= 0) return;
    if (n.isProbablePrime(10)) {
      int count = factors.containsKey(n) ? factors.get(n) : 0;
      factors.put(n, count+1);
      return;
    }
    BigInteger d = rho(n);
    pollard_rho(d);
    pollard_rho(n.divide(d));
  }

  public static void main(String[] args) {
    BigInteger n = sc.nextBigInteger();
    pollard_rho(n);
    
    for (Map.Entry<BigInteger, Integer> entry : factors.entrySet()) {
      pw.println(entry.getKey() + "^" + entry.getValue());
    }

    pw.close();    
  }
}

