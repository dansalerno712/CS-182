/*
 * MySorts.java
 *
 * I pledge my honor that I have abided by the Stevens Honor System
 *
 * Daniel Salerno
 *
 */
/**
 * A class that sorts arrays using the Selection Sort, Quicksort, and Radix Sort
 *
 * @author Dan Salerno
 * @since 20150203
 *
 */
public class MySorts {
    private static final int RADIX = 16;
    
    private static void swap(String[] arr, int index1, int index2) {
	String temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
    }
    private static void swap(int[] arr, int index1, int index2) {
       	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
    }
    private static void print(String[] arr) {
	if (arr == null) {
	    System.out.println("Array is null");
	} else {
	    for (String s: arr) {
		System.out.print(s + "\t");
	    }
	    System.out.println();
	}
    }
    private static void print(int[] arr) {
	if (arr == null) {
	    System.out.println("Array is null");
	} else {
	    for (int i: arr) {
		System.out.print(i + "\t");
	    }
	    System.out.println();
	}
    }
    private static boolean hasNoNulls(String[] arr) {
	for (int i = 0; i < arr.length; i++) {
	    if (arr[i] == null) {
		return false;
	    }
	}
	return true;
    }
    /*
     * Preconditions: -Non-null array of Strings arr
     *                -No null values in the array
     *                -int n > 1
     *
     * Postconditions: Array arr is stably sorted in ascending order
     *
     */
    public static void select(String[] arr, int n) {
	if (arr != null && n > 1 && hasNoNulls(arr)) { //error check
	    if (n > arr.length) {
		n = arr.length;
	    }
	    if (arr.length <= 1) { //dont run method if too small to be sorted
		MySorts.print(arr);
		return;
	    }
	    //marker for what indexes of arr are sorted
	    for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		//finds min
		for (int j = i + 1; j < n; j++) {
		    if (arr[j].compareTo(arr[minIndex]) < 0) {
			minIndex = j;
		    }
		}
		//swaps min to front if not already there
		if (minIndex != i) {
		    swap(arr, i, minIndex);
		}
	    }
	    MySorts.print(arr);
	} else {
	    System.out.println("Error: Invalid inputs");
	}
    }    
    private static void quicksort(String[] arr, int left, int right) {
	String pivot = arr[left + (right - left) / 2]; //use mid as pivot
	int i = left;
	int j = right;

	while (i <= j) {
	    while (arr[i].compareTo(pivot) < 0) { //go until arr[left] is greater than or equal to pivot
		i++;
	    }
	    while (arr[j].compareTo(pivot) > 0) { //go until arr[right] is less than or equal to  pivot
		j--;
	    }
	    if (i <= j) { //dont swap if it will unsort
		swap(arr, i, j);
		i++; //increment
		j--;
	    }
	}
	//recurse, keep going until left = j = 0 and i = right = n - 1
	if (left < j) {
	    quicksort(arr, left, j);
	}
	if (i < right) {
	    quicksort(arr, i, right);
	}
    }	
    /*
     * Preconditions: -Non-null array of Strings arr
     *                -No null values in the array
     *                -int n > 1
     *
     * Postconditions: Array arr is non-stably sorted in ascending order
     *
     */
    public static void quick(String[] arr, int n) {
	if (arr != null && n > 1 && hasNoNulls(arr)) { //E.C
	    if (n > arr.length) {
		n = arr.length;
	    }
	    if (arr.length <= 1) { //dont sort if too small
		MySorts.print(arr);
		return;
	    }
	    quicksort(arr, 0, n - 1); //left is beginning, right is end
	    MySorts.print(arr);
	}
	else {	   
	    System.out.println("Error: Invalid inputs");
	}
    }
    private static boolean hasNoNegatives(int[] arr) {
	for (int i = 0; i < arr.length; i++) {
	    if (arr[i] < 0) {
		return false;
	    }
	}
	return true;
    }
    /* 
     * Preconditions: -non null array of ints arr
     *                -int n > 1
     *                -all elements of arr are >= 0
     *
     * Postconditions: Array arr is stably sorted in ascending order
     *
     */
    public static void radix(int[] arr, int n) {
	if (arr != null && n > 1 && hasNoNegatives(arr)) { //E.C
	    if (n > arr.length) {
		n = arr.length;
	    }
	    if (arr.length <= 1) {
		MySorts.print(arr);
		return;
	    }
	    int [] count = new int[RADIX];
	    int [] b = new int[n];
	    int exp, max, i;
	    //find max
	    for (i = 1, max = arr[0]; i < n; i++) {
		if (arr[i] > max) {
		    max = arr[i];
		}
	    }
	    //find largest exponent needed
	    for (exp = 1; max / exp >= RADIX; exp *= RADIX)
		;
	    max = exp;
	    for (exp = 1; exp <= max && exp > 0; exp *= RADIX) {
		//clear count
		for (i = 0; i < RADIX; i++) {
		    count[i] = 0;
		}
		//count bucket sizes
		for (i = 0; i < n; i++) {
		    count[(arr[i] / exp) % RADIX]++;
		}
		//modify count
		for (i = 1; i < RADIX; i++) {
		    count[i] += count[i - 1];
		}
		//place items from a into  b
		for (i = n - 1; i >= 0; i--) {
		    b[--count[(arr[i] / exp) % RADIX]] = arr[i];
		}
		//b into a
		for (i = 0; i < n; i++) {
		    arr[i] = b[i];
		}
	    }
	    MySorts.print(arr);
	} else {
	    System.out.println("Error: Invalid inputs");
	}
    }
    /*
     * Preconditions: None
     * Postconditions: Tests all sorting algorithms
     *
     */
    public static void main(String[] args) {
	//Tests all variants and preconditions of selection sort
	String[] selectTest1 = {"cat", "a", "dog", "orange", "life", "aardvark", "Car", "", "track", "a"};
	String[] selectTest2 = {"cat", "a", "dog", "orange", "life", "aardvark", "Car", "", "track", "a"};
	String[] selectTest3 = {"cat", "a", "dog", "orange", "life", "aardvark", "Car", "", "track", "a"};
	String[] selectTest4 = new String[0];
	String[] selectTest5 = {"word"};
	System.out.println("Selection Sort Test:");
	MySorts.select(selectTest1, selectTest1.length); //tests standard full array sorting
	MySorts.select(selectTest2, 2); //tests partial array sorting
	MySorts.select(selectTest3, selectTest3.length + 10); //tests when n > arr.length
	MySorts.select(selectTest1, -1); //tests n < 1
	selectTest1[0] = null;
	MySorts.select(selectTest1, 5); //tests array with nulls
	selectTest1 = null;
	MySorts.select(selectTest1, 5); //tests null array
	MySorts.select(selectTest4, 5); //tests empty array
	MySorts.select(selectTest5, 10); //tests array with only one element

	//tests all variants and preconditions of quicksort
	String[] qs1 = {"a", "det", "c", "pisdh", "Aasd", "qwe", "ncbs", "", "yiasud", "bssdas", "frrrr", "a"};
	String[] qs2 = {"a", "det", "c", "pisdh", "Aasd", "qwe", "ncbs", "", "yiasud", "bssdas", "frrrr", "a"};
	String[] qs3 = {"a", "det", "c", "pisdh", "Aasd", "qwe", "ncbs", "", "yiasud", "bssdas", "frrrr", "a"};
	String[] qs4 = new String[0];
	String[] qs5 = {"hi"};
	System.out.println("Quicksort test");
	MySorts.quick(qs1, qs1.length); //full array sorting
	MySorts.quick(qs2, 4); //partial array sorting
	MySorts.quick(qs3, qs3.length + 10); //n > arr.length
	MySorts.quick(qs1, -1); //n < 1
	qs1[0] = null;
	MySorts.quick(qs1, 5); //array with nulls
	qs1 = null;
	MySorts.quick(qs1, 5); //null array
	MySorts.quick(qs4, 5); //empty array
	MySorts.quick(qs5, 5); //arr with only one element
	
	//tests all variants and preconditions of radix sort
	int[] r1 = {10, 1, 5, 16, 2, 5, 3};
	int[] r2 = {0, 0, 0, 10, 2, 100000000, 6948394, 50, 234, 34645, 123, 662344};
	int[] r3 = {10, 4, 2352, 65, 903, 43, 23, 0, 44, 44, 2};
	int[] r4 = {-1, 10, 5, 3};
	int[] r5 = new int[0];
	int[] r6 = {1};
	System.out.println("Radix Sort Test");
	MySorts.radix(r1, r1.length); //full array sorting
	MySorts.radix(r2, 6); //partial array sorting
	MySorts.radix(r3, r3.length + 3); //n > arr.length
	MySorts.radix(r1, -3); //n < 1
	MySorts.radix(r4, 5); //negatives in arr
	r1 = null;
	MySorts.radix(r1, 4); //null array
	MySorts.radix(r5, 5); //empty array
	MySorts.radix(r6, 6); //arr with one element
    }
}
	
	
	
