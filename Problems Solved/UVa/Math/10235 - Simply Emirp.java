import java.io.*;
import java.util.*;
import java.math.*;

class Main {
  public static void main(String args[]) {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    Scanner sc = new Scanner(br);
    PrintWriter pw = new PrintWriter(bw);

    while (sc.hasNext()) {
      String s = sc.next();
      BigInteger a = new BigInteger(s); 
      BigInteger b = new BigInteger(new StringBuffer(s).reverse().toString());

      if (a.isProbablePrime(10)) {
        if (!(b.equals(a)) && b.isProbablePrime(10))
          pw.println(s + " is emirp."); 
        else 
          pw.println(s + " is prime."); 
      }
      else 
        pw.println(s + " is not prime.");
    }

    pw.close();
  }
}
