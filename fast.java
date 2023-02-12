import java.util.Random;

class fast {
  public static void main(String args[]) {
   Random rm = new Random();
   String wc = " | wc -l";
   String checker = " | ./tester $ARG";
  String txt = "ARG=\"";
    for(int i = 0; i < 500; i ++)// number of test
    {
          for(int j = 0; j < 100 ; j ++) // number of number
    {
      txt += - rm.nextInt(10000000) + " "; // bound of number [0,x]
    }
      System.out.println(txt + "\" ; ./a.out $ARG " + wc);
      txt = "ARG=\"";
    }

  }
}
