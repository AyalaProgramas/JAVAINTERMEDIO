package program;

import entities.Computer;
import entities.computerStages;

public class Program {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Computer c=new Computer();
			
			c.changeaState(computerStages.ON);
			
			//no se puede instanciar un enumerado
			computerStages cs=computerStages.ON;
			System.out.println(cs.getDescription());
			
			
			
	}

}
