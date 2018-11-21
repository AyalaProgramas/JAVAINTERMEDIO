import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;


public class Program {

	public static void main(String[] args) {
		
		if(args.length==2)
		{
			try
			{
			InputStream is=new FileInputStream(args[0]);
			OutputStream os=new FileOutputStream(args[1]);
			
			if(args[0]!=null&&args[1]!=null)
			{
				leerCompleto(is,os);
			}
			else
			{
				System.out.println("error");
			}
			
			}catch(FileNotFoundException e)
			{
				
				e.printStackTrace();
				
			}
		}
		else
		{
			System.out.println("solo se ingreso dos argumentos");
		}

	}
	
	
	public static void leerCompleto(InputStream fis,OutputStream fos)
	{
		int totalSize;
		int porcen;
		int i=0;
		
		
		try
		{
			totalSize=fis.available();
			while(fis.available()>0)
			{
				i++;
				float p=i*100/totalSize;
				int foo=fis.read();
				System.out.println(p);
				System.out.println("\n\n\n\n");
				fos.write(foo);
				//System.out.println(fis.read());
				
			}
			
			
		}
		catch (FileNotFoundException e)
		{
			e.printStackTrace();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		
		finally
		{
			try
			{
				fis.close();
				fos.close();
			}catch(Exception e)
			{
				e.printStackTrace();
			}
		}
	}
}

//ejecutable
