import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class ShellCmd
{
  public static void main (String args[])
  {
    try {
    String cmd = "ls -al";

    Runtime run = Runtime.getRuntime ();

    Process pr = run.exec (cmd);

      pr.waitFor ();

    BufferedReader buf =
      new BufferedReader (new InputStreamReader (pr.getInputStream ()));

    String line = "";

    while ((line = buf.readLine ()) != null)
      {

	System.out.println (line);

      }
    } catch (Exception e)
    {
	    System.out.println("Exception details: "+e);
    }
 }
}
