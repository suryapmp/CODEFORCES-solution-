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
		System.out.println(solve(a));

		sc.close();
	}

	static int solve(int[] a) {
		int min = Arrays.stream(a).min().getAsInt();
		int[] indices = IntStream.range(0, a.length).filter(i -> a[i] == min).toArray();

		return IntStream.range(0, indices.length - 1).map(i -> indices[i + 1] - indices[i]).min().getAsInt();
	}
}
