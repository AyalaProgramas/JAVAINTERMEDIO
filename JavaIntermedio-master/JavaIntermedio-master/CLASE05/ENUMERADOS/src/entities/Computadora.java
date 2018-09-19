package entities;

public class Computadora {
		computerStages state=computerStages.OFF;
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
