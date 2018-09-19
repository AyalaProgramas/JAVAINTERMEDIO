package singleton;
//esta clase se instancia una vez

 class DBconnection {
		
	private static DBconnection instance;
	//ejemplo del patron singleton el adcede con objetivo de sacar la infor macion
	//lo instancia solo una vez 
	//
	public static DBconnection getinstance()
	{
		if(instance==null)
		{
			instance=new DBconnection();
		}
		return instance;
	}
	
	/*private String dbAddress,dbname;
	
	
	public String getDbname() {
		return dbname;
	}



	public String getDbAddress() {
		return dbAddress;
	}


	public DBconnection()
	{
	
	}*/
	
}
