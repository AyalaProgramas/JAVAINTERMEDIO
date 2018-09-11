package sustitucion.program;

public class Program {

	public static void main(String[] args) {
			claseB cb=new claseB();
			
			claseA ad=new claseB(); //llamada de metodo virtual
			//cb.metodo();
			cb.metodoA();//no puedo adceder al metodo de la clase a xeso hago este metodo
			
			claseA av=new claseB();
			//av.otrometodo();
			
			if(av instanceof claseB)
			{
				((claseB)av).otrometodo();
				
			}
			else{
				
				System.out.println("no se puede castear la referencia");
			
			}
			
			
			
			//polimorfismo
			
			//conversion
			
			
			
	}

}
