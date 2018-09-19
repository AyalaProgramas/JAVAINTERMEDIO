package entities;

public class Computer {
	
	computerStages state=computerStages.OFF;
	
	public computerStages getState()
	{
		return state;
	}
	
	
	public void changeaState(computerStages newState)
	{
		state = newState;
		
		switch(state)
		{
			case OFF:
				System.out.println("apagando");
			case ON:
				System.out.println("apagando");
			case SUSPENDED:
				System.out.println("suspendido");
		}
	}
}
