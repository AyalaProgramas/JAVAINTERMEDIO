package ejemplo;

public class calseDAOFactory {
		public InterfaceDAO createInstance(int tipo)
		{
			InterfaceDAO instance=null;
			
			switch(tipo)
			{
				case 0:
					instance=new ClaseDAODB();
					break;
					
				case 1:
					instance=new ClaseDAOMEMORIA();
					break;
					
			}
			return instance;
		}
}
