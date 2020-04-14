import java.text.DecimalFormat;

public class Time implements Comparable <Time>
{
 private int hour, minute, second; // atributos privados do tempo

 public Time () // construtor nulo
 { hour = minute = second = 0; }

 // construtor inicializador
 public Time (int pHour, int pMin, int pSec) throws IllegalTimeException
 {
  if (validTime (pHour, pMin, pSec))
  { hour = pHour; minute = pMin; second = pSec; }
  else throw new IllegalTimeException ();
 }

 public Time (Time pTime) // construtor copia
 {
  if (pTime != null)
  { hour = pTime.getHour (); minute = pTime.getMinute (); second = pTime.getSecond (); }
 }

  // construtor de tempo total em segundos
 public Time (int pTotalTime) throws IllegalTimeException
 {
	 
  int h = pTotalTime / 3600; // calcular as horas
  pTotalTime = pTotalTime % 3600; // calcular os restantes segundos
  int m = pTotalTime / 60; // calcular os minutos
  int s = pTotalTime % 60; // calcular os segundos

  if (validTime (h, m, s)) { hour = h; minute = m; second = s; }
  else throw new IllegalTimeException ();
 }

 public int getHour () // selector da componente horas
 { return hour; }

 public int getMinute () // selector da componente minutos
 { return minute; }

 public int getSecond () // selector da componente segundos
 { return second; }

 public void setHour (int pHour) // modificador da componente horas
 { if (pHour >= 0 && pHour <= 23) hour = pHour; }

 public void setMinute (int pMin) // modificador da componente minutos
 { if (pMin >= 0 && pMin <= 59) minute = pMin; }

 public void setSecond (int pSec) // modificador da componente segundos
 { if (pSec >= 0 && pSec <= 59) second = pSec; }

 public boolean isZero () // comparador de nulidade
 { return hour == 0 && minute == 0 && second == 0; }

 public boolean equals (Object pObj) // comparador de igualdade
 {
  if (this == pObj) return true;
  if (!(pObj instanceof Time)) return false;

  Time time = (Time) pObj;
  return (hour == time.getHour () && minute == time.getMinute () 
			&& second == time.getSecond ());
 }

 public int compareTo (Time pTime) // operador relacional (> == <)
 { return this.totalSeconds () - pTime.totalSeconds (); }

 public String toString () // tempo no formato hh:mm:ss
 {
  DecimalFormat twoDigits = new DecimalFormat ("00");
  
  return twoDigits.format (hour) + ":" + twoDigits.format (minute) + ":" 
		 + twoDigits.format (second);
 }

 // tempo seguinte (mais um segundo)
 public Time nextTime () throws IllegalTimeException
 {
  int h = hour, m = minute, s = second;

  if (s < 59) s++;
  else
  {
   s = 0;
   if (m < 59) m++; else { m = 0; h++; }
  }

  if (h > 23) throw new IllegalTimeException ();
  else return new Time (h, m, s);
 }

 // tempo anterior (menos um segundo)
 public Time previewTime () throws IllegalTimeException
 {
  int h = hour, m = minute, s = second;

  if (s > 1) s--;
  else
  {
   s = 59;
   if (m > 1) m--; else { m = 59; h--; }
  }
 
  if (h < 0) throw new IllegalTimeException ();
  else return new Time (h, m, s);
 }

 // somar dois tempos
 public Time addTime (Time pTime) throws IllegalTimeException
 {
  if (pTime == null) return null;

  int h = hour, m = minute, s = second;
  
  s += pTime.getSecond ();
  if (s > 59) { m++; s -= 60; }
  m += pTime.getMinute ();
  if (m > 59) { h++; m -= 60; }
  h += pTime.getHour ();

  if (h > 23) throw new IllegalTimeException ();
  else return new Time (h, m, s);
 }

 // subtrair dois tempos
 public Time subTime (Time pTime) throws IllegalTimeException, NullPointerException
 {
  if (pTime == null) throw new NullPointerException ();
  if (this.compareTo (pTime) < 0) throw new IllegalTimeException ();

  int h = hour, m = minute, s = second;

  s -= pTime.getSecond ();
  if (s < 0) { m--; s += 60; }
  m -= pTime.getMinute ();
  if (m < 0) { h--; m += 60; }
  h -= pTime.getHour ();
  
  return new Time (h, m, s);
 }

 // metodo privado para converter o tempo para segundos
 private int totalSeconds ()
 { return hour * 3600 + minute * 60 + second; }

 // metodo privado para validar o tempo
 private static boolean validTime (int pHour, int pMin, int pSec)
 {
   if (pHour < 0 || pHour > 23 || pMin < 0 || pMin > 59 || pSec < 0 || pSec > 59)
		return false;
   else return true;
 }
}
