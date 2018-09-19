package entities;
import interfaces.Interface;

public class Plane extends Vehiculo implements Interface {
	
	
		private int maxAltitude;

		public int getMaxAltitude() {
			return maxAltitude;
		}
			
		public void setMaxAltitude(int maxAltitude) {
			this.maxAltitude = maxAltitude;
		}
		
		
		
		
}
