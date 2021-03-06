import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int t = sc.nextInt();
    for (int tc = 0; tc < t; ++tc) {
      sc.nextInt();
      String s = sc.next();

      System.out.println(solve(s));
    }

    sc.close();
  }

  static String solve(String s) {
    return IntStream.range(0, s.length() - 1)
        .filter(i -> s.charAt(i) != s.charAt(i + 1))
        .mapToObj(i -> String.format("%d %d", i + 1, i + 2))
        .findAny()
        .orElse("-1 -1");
  }
}
