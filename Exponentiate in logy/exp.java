public class exp {
    public static int exp(int x, int y) {
	if (y == 0) {
	    return 0;
	}
	if (y == 1) {
	    return x;
	}
	if (y % 2 == 0) {
	    return exp(x * x, y / 2);
	} else {
	    return x * exp(x * x, (y - 1) / 2);
	}
    }
    public static void main(String[] args) {
	System.out.println(exp.exp(2, 5));
    }
}
