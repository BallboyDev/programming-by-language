import java.math.BigDecimal;
import java.math.RoundingMode;

public class BigDecimalSample1{
    public static void main(String args[]){

        // [1] 더하기
        BigDecimal value1 = new BigDecimal("0.7");
        BigDecimal value2 = new BigDecimal("0.1");
        BigDecimal result = value1.add(value2);
        System.out.println("[1] 0.7 + 0.1 = " + result);

        // [2] 빼기
        result = value1.subtract(value2);
        System.out.println("[2] 0.7 - 0.1 = " + result);

        // [3] 곱하기
        result = value1.multiply(value2);
        System.out.println("[3] 0.7 * 0.1 = " + result);

        // [4] 나누기
        value1 = new BigDecimal("7.0");
        value2 = new BigDecimal("3.0");
        // 소수점 미만을 내림(버림)
        result = value1.divide(value2, 0, RoundingMode.DOWN);
        System.out.println("[4] 7.0 + 3.0 = " + result);

        // [5] 나머지
        value1 = new BigDecimal("7.0");
        value2 = new BigDecimal("3.0");
        result = value1.remainder(value2);
        System.out.println("[5] 7.0 % 3.0 = " + result);
    }
}