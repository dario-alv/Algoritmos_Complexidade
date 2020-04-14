
import static java.lang.System.*;
import java.util.Scanner;

public class TestTime
{
  final static Scanner in = new Scanner(System.in);

  static int leOpcao ()
  {
    int result;

    out.printf("1. Criar um tempo indicado como hh:mm:ss\n");
    out.printf("2. Criar um tempo indicado em segundos\n");
    out.printf("3. Tempo seguinte\n");
    out.printf("4. Tempo anterior\n");
    out.printf("5. Somar tempos\n");
    out.printf("6. Subtrair tempos\n");
    out.printf("0. Terminar\n\n");
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
          if (t1 != null) out.printf ("Tempo > %s\n", t1.toString ());
          else  out.printf ("Tempo invalido\n");
          break;

        case 2:
          out.print ("tempo total em segundos: ");
          int segundos = in.nextInt ();
          try
          {
			t1 = new Time (segundos);
			out.printf ("Tempo > " + t1.toString ());
          }
          catch (IllegalTimeException e)
          {
			 t1 = null;
			 out.printf ("Tempo invalido\n");
		  }
          break;

        case 3:
          t1 = readTime ();
          if (t1 != null) out.printf ("Tempo > %s\n", t1.toString ());
          else {  out.printf ("Tempo invalido\n"); break; }

          try
          {
			tr = t1.nextTime ();
			out.printf ("Tempo seguinte > %s\n", tr.toString ());
          }
          catch (IllegalTimeException e)
          {
			 tr = null;
			 out.printf ("Tempo seguinte inexistente\n");
		  }
          break;

        case 4:
          t1 = readTime ();
          if (t1 != null) out.printf ("Tempo > %s\n", t1.toString ());
          else {  out.printf ("Tempo invalido\n"); break; }

          try
          {
			tr = t1.previewTime ();
			out.printf ("Tempo anterior > %s\n", tr.toString ());
          }
          catch (IllegalTimeException e)
          {
			 tr = null;
			 out.printf ("Tempo anterior inexistente\n");
		  }
          break;

        case 5:
          t1 = readTime ();
          if (t1 != null) out.printf ("Tempo > %s\n", t1.toString ());
          else {  out.printf ("Tempo invalido\n"); break; }

          t2 = readTime ();
          if (t2 != null) out.printf ("Tempo > %s\n", t2.toString ());
          else {  out.printf ("Tempo invalido\n"); break; }

          try
          {
			tr = t1.addTime (t2);
			out.printf ("Tempo soma > %s\n", tr.toString ());
          }
          catch (IllegalTimeException e)
          {
			 tr = null;
			 out.printf ("Tempo soma inexistente\n");
		  }
          break;

        case 6:
          t1 = readTime ();
          if (t1 != null) out.printf ("Tempo > %s\n", t1.toString ());
          else {  out.printf ("Tempo invalido\n"); break; }

          t2 = readTime ();
          if (t2 != null) out.printf ("Tempo > %s\n", t2.toString ());
          else {  out.printf ("Tempo invalido\n"); break; }

          try
          {
			tr = t1.subTime (t2);
			out.printf ("Tempo dif > %s\n", tr.toString ());
          }
          catch (IllegalTimeException e)
          {
			 tr = null;
			 out.printf ("Tempo dif inexistente\n");
		  }
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
    
    try
    { return new Time (h, m, s); }
	catch (IllegalTimeException e)
	{ return null; }
  }
}
