import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner num = new Scanner(System.in);
        int a = num.nextInt();
        int b = num.nextInt();
        System.out.println(a+b);
        num.close();
    }
}
