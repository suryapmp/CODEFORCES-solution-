import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.nextInt();
		}
		System.out.println(solve(a) ? "YES" : "NO");

		sc.close();
	}

	static boolean solve(int[] a) {
		Arrays.sort(a);

		return IntStream.range(2, a.length).anyMatch(i -> a[i - 2] + a[i - 1] > a[i]);
	}
}