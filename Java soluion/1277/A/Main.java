import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		for (int tc = 0; tc < t; tc++) {
			int n = sc.nextInt();

			System.out.println(solve(n));
		}

		sc.close();
	}

	static int solve(int n) {
		int result = 0;
		for (int digit = 1; digit <= 9; digit++) {
			long beautiful = digit;
			while (beautiful <= n) {
				result++;
				beautiful = beautiful * 10 + digit;
			}
		}

		return result;
	}
}
