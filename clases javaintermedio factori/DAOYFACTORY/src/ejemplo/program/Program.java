package ejemplo.program;

import ejemplo.*;
public class Program {

	public static void main(String[] args) {
			
			calseDAOFactory fabrica=new calseDAOFactory();
			InterfaceDAO dao =fabrica.createInstance(1);
			//InterfaceDAO dao =new ClaseDAOMEMORIA();
			dao.writen();
			
			
			
	}

}
