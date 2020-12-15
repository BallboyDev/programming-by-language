public class ArithmeticOperator1{
    public static void main(String args[]){
        // [1] 특수한 계산
        int result = 1;
        result += 2;

        System.out.println("[1] result = 1 -> result += 2 -> result = " + result);

        // [2] 특수한 계산
        System.out.println("[2] result = 1 -> ++result");
        result = 1;
        printValue(++result);
        System.out.println("result = " + result);

        // [3] 특수한 계산
        System.out.println("[3] result = 1 -> result++");
        result = 1;
        printValue(result++);
        System.out.println("result = " + result);
    }

    private static void printValue(int value){
        System.out.println("전달된 값: value = " + value);
    }
}