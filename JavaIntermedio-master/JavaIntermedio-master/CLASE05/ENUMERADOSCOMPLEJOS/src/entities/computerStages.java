package entities;

public enum computerStages {
		OFF("representa el estado apagado de la computadora"),//
		ON("represanta el estado prendido ede la computadora"),
		SUSPENDED("representa el estado suspendido de la computadora");
		
		private String description="";
		
		public String getDescription()
		{
			return description;
		}
		
		//creamos contructor
		//el constructor privado solo trabaja en la clase
		
		private computerStages(String description)
		{
			this.description=description;
		}
		
}
