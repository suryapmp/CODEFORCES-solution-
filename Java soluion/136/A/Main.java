import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int[] p = new int[n];
		for (int i = 0; i < p.length; i++) {
			p[i] = sc.nextInt();
		}
		System.out.println(String.join(" ", Arrays.stream(solve(p)).mapToObj(String::valueOf).toArray(String[]::new)));

		sc.close();
	}

	static int[] solve(int[] p) {
		int[] result = new int[p.length];
		for (int i = 0; i < p.length; i++) {
			result[p[i] - 1] = i + 1;
		}
		return result;
	}
}
