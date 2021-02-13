public class CmdLineArgs {
	public static void main(String[] args) {
		for(int word = args.length - 1; word >= 0; word--) {
			for(int character = args[word].length() - 1; character >= 0; character--) {
				System.out.print(args[word].toCharArray()[character]);
			}
			System.out.print(" ");
		}
		System.out.println();
	}
}
