import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		for (int tc = 0; tc < t; tc++) {
			int n = sc.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = sc.nextInt();
			}

			System.out.println(solve(a));
		}

		sc.close();
	}

	static int solve(int[] a) {
		int result = 0;
		int rightMin = Integer.MAX_VALUE;
		for (int i = a.length - 1; i >= 0; i--) {
			if (a[i] > rightMin) {
				result++;
			}

			rightMin = Math.min(rightMin, a[i]);
		}

		return result;
	}
}
