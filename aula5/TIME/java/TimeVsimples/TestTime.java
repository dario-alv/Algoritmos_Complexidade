
import static java.lang.System.*;
import java.util.Scanner;

public class TestTime
{
  final static Scanner in = new Scanner(System.in);

  static int leOpcao ()
  {
    int result;

    out.println("1. Criar um tempo indicado como hh:mm:ss");
    out.println("2. Criar um tempo indicado em segundos");
    out.println("3. Tempo seguinte");
    out.println("4. Tempo anterior");
    out.println("5. Somar tempos");
    out.println("6. Subtrair tempos");
    out.println("0. Terminar");
    out.println();
    out.print("Opcao: ");
    do
    {
      result = in.nextInt ();
      in.nextLine ();
    }
    while (result < 0 || result > 6);

    return result;
  }


  static public void main (String[] args)
  {
    int op;
    Time t1 = null, t2 = null, tr = null;

    do
    {
      op = leOpcao ();
      switch (op)
      {
        case 1:
          t1 = readTime ();
          out.println ("Tempo > " + t1.toString ());
          break;
        case 2:
          int segundos;
          out.print ("tempo total em segundos: ");
          segundos = in.nextInt ();
          t1 = new Time (segundos);
          out.println ("Tempo > " + t1.toString ());
          break;
        case 3:
          t1 = readTime ();
          out.println ("Tempo > " + t1.toString ());
          tr = t1.nextTime ();      
          if (tr != null) out.println ("Tempo seguinte > " + tr.toString ());
          else out.println ("Tempo seguinte inexistente\n"); 
          break;
        case 4:
          t1 = readTime ();
          out.println ("Tempo > " + t1.toString ());
          tr = t1.previewTime ();
          if (tr != null) out.println ("Tempo anterior > " + tr.toString ());
		  else out.println ("Tempo anterior inexistente\n"); 
          break;
        case 5:
          t1 = readTime ();
          out.println ("Tempo 1  > " + t1.toString ());
          t2 = readTime ();
          out.println ("Tempo 2 > " + t2.toString ());
          tr = t1.addTime (t2);
          if (tr != null) out.println ("Tempo soma > " + tr.toString ());
		  else out.println ("Tempo soma inexistente\n"); 
          break;
        case 6:
          t1 = readTime ();
          out.println ("Tempo 1  > " + t1.toString ());
          t2 = readTime ();
          out.println ("Tempo 2 > " + t2.toString ());
          tr = t1.subTime (t2);
          if (tr != null) out.println ("Tempo dif > " + tr.toString ());
		  else out.println ("Tempo dif inexistente\n"); 
          break;
      }
    } while(op != 0);
  }

  public static Time readTime ()
  {
    out.print ("horas: ");
    int h = in.nextInt ();
    out.print ("minutos: ");
    int m = in.nextInt ();
    out.print ("segundos: ");
    int s = in.nextInt ();
    return new Time (h, m, s);
  }
}
