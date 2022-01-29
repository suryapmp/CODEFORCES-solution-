import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int q = sc.nextInt();
		for (int tc = 0; tc < q; tc++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();

			System.out.println(solve(a, b, c));
		}

		sc.close();
	}

	static int solve(int a, int b, int c) {
		return Math.max(0, IntStream.of(a, b, c).max().getAsInt() - IntStream.of(a, b, c).min().getAsInt() - 2) * 2;
	}
}
