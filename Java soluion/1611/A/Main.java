import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int t = sc.nextInt();
    for (int tc = 0; tc < t; ++tc) {
      int n = sc.nextInt();

      System.out.println(solve(n));
    }

    sc.close();
  }

  static int solve(int n) {
    if (n % 2 == 0) {
      return 0;
    }

    String s = String.valueOf(n);
    if ((s.charAt(0) - '0') % 2 == 0) {
      return 1;
    }

    return s.chars().anyMatch(ch -> (ch - '0') % 2 == 0) ? 2 : -1;
  }
}
